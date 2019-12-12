/*************************************************************************
    > File Name: allcodecs.c
    > Author: albertfang
    > Mail: fang.qi@besovideo.com 
    > Created Time: 2015年03月23日 星期一 11时41分56秒
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

#line 25 "allcodecs.c"

#include "avcodec.h"
#include <config.h>

#define REGISTER_PARSER(X, x)                                           \
    {                                                                   \
        extern AVCodecParser av_##x##_parser;                           \
        if (AV_CONFIG_##X##_PARSER)                                     \
            av_codec_parser_register(&av_##x##_parser);                 \
    }

#if 0
#define REGISTER_ENCODER(X, x)                                          \
    {                                                                   \
        extern AVCodec av_##x##_encoder;                                \
        if (AV_CONFIG_##X##_ENCODER)                                    \
            av_codec_register(&av_##x##_encoder);                       \
    }

#define REGISTER_DECODER(X, x)                                          \
    {                                                                   \
        extern AVCodec av_##x##_decoder;                                \
        if (AV_CONFIG_##X##_DECODER)                                    \
            av_codec_register(&av_##x##_decoder);                       \
    }

#endif
void av_codec_register_all(void)
{
    static int initialized;
    if (initialized)
        return;
    initialized = 1;

    REGISTER_PARSER(H264, h264);
}

