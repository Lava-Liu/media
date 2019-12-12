#ifndef _STUDENT_H_
#define _STUDENT_H_

#define NAME_LEN 20
#define CODE 1000
#define SCORE 0.0

//添加一个新的学生信息
int add_student(char *name,double score);
//修改一个学生的信息
int modify_student(int code,double newscore);
//察看学生基本信息
int query_student(int code);




#endif
