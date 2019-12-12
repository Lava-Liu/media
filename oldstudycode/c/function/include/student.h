#ifndef _STUDENT_H_
#define _STUDENT_H_
#define CODE 1000
#define NAME_LEN 20
#define SCORE 0.0
int add_student(char*name,double score);
int modify_score(int code,double newscore);

int query_student(int code);



#endif
