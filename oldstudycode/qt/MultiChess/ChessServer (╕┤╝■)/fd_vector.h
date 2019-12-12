#ifndef FD_VECTOR_H
#define FD_VECTOR_H


typedef struct
{
    int *fds;
    int count;
    int max;
}Fd_Vector;

extern Fd_Vector* create_fd_v();

extern void delete_fd_v(Fd_Vector *v);

extern void add_fd_v(Fd_Vector *v,int fd);

//删除表里面删除指定的套结字描述符
extern void delete_fd_v(Fd_Vector *v,int fd);

//查找fd在顺序表中的数组的下标
extern int get_fd_index(Fd_Vector *v,int fd);





#endif // FD_VECTOR_H
