#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 004
#define K 1024
int shmid;

int main(){
int i,*pint;
char *addr;
shmid=shmget(SHMKEY,8*K,0777); /*取共享去SHMKEY的id*/
addr=shmat(shmid,0,0);	/*连接共享区*/
pint=(int*)addr;
for(i=0;i<256;i++)
{
printf("%d\n",*pint++);	/*打印共享区中的内容*/
}
}
