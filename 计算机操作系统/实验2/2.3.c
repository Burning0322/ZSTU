#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 004  //学号末三位
#define K 1024
int pshmid; //parent
int cshmid; //childint
int main() {
    int i, *pint, x;
    int delete;
    char *paddr , *caddr , *paddr2, c;
    char words[26]= {'A','B','C','D','E','F','G','H' ,'I','J',
                     'K','L','M','N','O','P','Q','R','S',
                     'T','U','V','W','X','Y','Z'};
    while((x = fork()) == -1 );
    if(x == 0) {
        printf( "子进程!\n");
        cshmid = shmget(SHMKEY, 30*K, 0666);//子进程建立30共享区
        caddr = shmat(cshmid, 0, 0);  //挂接得到共享区首地址
        for(i = 0; i <= 25; i++) {
            printf( "%c  ", *caddr);  //读出数据
            *caddr = (*caddr + 'a'-'A');     //取到小写
            caddr++;
            if(i == 25)
                printf( "\n");
        }
        delete = shmdt(caddr); //释放
        exit(0);
    }else {
        printf( "父进程!\n" );
        pshmid = shmget(SHMKEY, 30*K, 0666| IPC_CREAT); //建立30K共享区
        paddr = shmat(pshmid, 0, 0);  //挂接得到共享区首地址
        paddr2 = paddr; //挂接得到读小写
        for(i = 0; i <= 25; i++) {
            *paddr++ = words[i];   //往共享区写入大写字母
        }
        sleep(5);
        for(i = 0; i <= 25; i++){
            printf( "%c  ", *paddr2++); //读出数据
            if(i == 25)
                printf( "\n" );
        }
    }
    return 0;
}
