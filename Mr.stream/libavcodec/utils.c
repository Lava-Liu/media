/*************************************************************************
    > File Name: utils.c
    > Author: albertfang
    > Mail: fang.qi@besovideo.com 
    > Created Time: 2015年03月23日 星期一 12时03分19秒
 ************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) albert@BesoVideo, 2015
 */

#line 25 "utils.c"

#include <libavutil/atomic.h>
#include <libavutil/avassert.h>

#include "avcodec.h"

static AVCodecParser *first_parser = NULL;
static AVCodecParser **last_parser = &first_parser;

void av_codec_parser_register(AVCodecParser *parser)
{
    AVCodecParser **p = last_parser;
    parser->next = NULL;
    while (*p || avpriv_atomic_ptr_cas((void *volatile *) p, NULL, parser))
        p = &(*p)->next;
    last_parser = &parser->next;
}

AVCodecParser *av_codec_parser_next(const AVCodecParser *p)
{
    if (p)
        return p->next;
    else
        return first_parser;
}

AVCodecParserContext *av_codec_parser_alloc(void)
{
    AVCodecParserContext *s = av_mallocz(sizeof(AVCodecParserContext));
    if (!s) {
        av_log(NULL, AV_LOG_ERROR, "av codec parser alloc error\n");
    }
    return s;
}

void av_codec_parser_free(AVCodecParserContext *s)
{
    if (!s) {
        return;
    }
    av_free(s->priv_data);
    av_free(s);
    return;
}

AVCodecParserContext *av_codec_parser_init(enum AVCodecID codec_id)
{
    AVCodecParserContext *parser_context = NULL;
    AVCodecParser *parser = NULL;
    int ret = 0;
    if (codec_id == AV_CODEC_ID_NONE) {
        return NULL;
    }
    while ((parser = av_codec_parser_next(parser))) {
        if (parser->codec_ids[0] == codec_id ||
            parser->codec_ids[1] == codec_id ||
            parser->codec_ids[2] == codec_id ||
            parser->codec_ids[3] == codec_id ||
            parser->codec_ids[4] == codec_id) {
            goto found;
        }
    }
    return NULL;
found:
    parser_context = av_codec_parser_alloc();
    if (!parser_context) {
        return NULL;
    }
    parser_context->parser = parser;
    if (parser->priv_data_size) {
        parser_context->priv_data = av_mallocz(parser->priv_data_size);
        if (!parser_context->priv_data)
            goto fail;
    }

    if (parser->parser_init) {
        ret = parser->parser_init(parser_context);
        if (ret != 0)
            goto fail;
    }
    return parser_context;
fail:
    av_codec_parser_free(parser_context);
    return NULL;
}

int av_codec_parser_exit(AVCodecParserContext *s)
{
    if (!s)
        return AVERROR(EINVAL);
    if (s->parser && s->parser->parser_exit) {
        s->parser->parser_exit(s);
    }
    av_codec_parser_free(s);
    return 0;
}

int av_codec_parser_parse(AVCodecParserContext *s, AVCodecContext *codec, const uint8_t *data_in, int data_in_size, const uint8_t **data_out, int *data_out_size)
{
    if (!s || !s->parser) {
        return AVERROR(EINVAL);
    }
    if (!s->parser->parser_parse) {
        return AVERROR(ENOSYS);
    }
    if (!data_in || data_in_size <= 0) {
        av_log(s, AV_LOG_ERROR, "input data size error\n");
        return AVERROR(EINVAL);
    }
    return s->parser->parser_parse(s, codec, data_in, data_in_size, data_out, data_out_size);
}
