#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMKEY 004  /*在实际实验过程中，为了避免每个同学建立的共享存储区关键字一样而相互干扰，关键字请用学号末3位*/
#define K  1024
int shmid;
main ()
 {
int i,*pint;
char *addr;
extern cleanup ();/*共享区删除函数*/
for(i=0;i<20;i++) signal(i,cleanup);
shmid=shmget(SHMKEY,16*K,0777|IPC_CREAT); /*建立16K共享区SHMKEY */
addr=shmat(shmid,0,0);/*挂接，并得到共享区首地址 */
printf ("addr 0x%x\n",addr);
pint=(int *)addr;
for (i=0;i<256;i++) *pint++=i;
pause();/*等待接收进程读 */
 }
cleanup()
{
shmctl(shmid,IPC_RMID,0);
exit (0);
}

