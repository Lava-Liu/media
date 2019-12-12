#ifndef _PV_H_
#define _PV_H_

extern int  I(int semnum,int val);
extern void P(int semid,int semnum,int val);
extern void V(int semid,int semnum,int val);
extern void D(int semid);







#endif
