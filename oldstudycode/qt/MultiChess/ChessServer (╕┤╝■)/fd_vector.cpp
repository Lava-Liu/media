#include <fd_vector.h>
#include <command.h>




Fd_Vector* create_fd_v()
{
    Fd_Vector *vector = (Fd_Vector *)malloc(sizeof(Fd_Vector));
    assert(vector!=NULL);

    vector->fds = (int *)calloc(10,sizeof(int));
    assert(vector->fds != NULL);

    vector->count=0;
    vector->max=10;
    return vector;
}

void delete_fd_v(Fd_Vector *v)
{
    assert(v!=NULL);
    free(v->fds);
    v->fds = NULL;
    free(v);
    v=NULL;
}

//扩展顺序表的大小
static void en_fd_v(Fd_Vector *v)
{
    int *p = (int *)realloc(v->fds,sizeof(int)*(v->max+5));
    assert(p != NULL);
    if(p != v->fds)
    {
        //首先释放之前的数组空间（已经没用了）
        free(v->fds);
        v->fds=p;
        p =NULL;
    }
    v->max+=5;
}

void add_fd_v(Fd_Vector *v,int fd)
{
    assert(v!=NULL);
    if(v->count >= v->max)
    {
        en_fd_v(v);
    }
    v->fds[v->count]=fd;
    v->count++;

}

//删除表里面删除指定的套结字描述符
void delete_fd_v(Fd_Vector *v,int fd)
{
    assert(v!=NULL);
    int i=0;
    for( i;i < v->count;i++)
    {
        if(fd == v->fds[i])
        {
            int j=i;
            for(j; j< v->count;j++)
            {
                v->fds[j]=v->fds[j+1];
            }
            v->fds[v->count]=0;
            v->count--;
        }
    }
}

//查找fd在顺序表中的数组的下标
int get_fd_index(Fd_Vector *v,int fd)
{
    assert(v!=NULL);
    int i=0;
    for(i;i<v->count;i++)
    {
        if(v->fds[i] == fd)
        {
            return i;
        }
    }
    return -1;
}


