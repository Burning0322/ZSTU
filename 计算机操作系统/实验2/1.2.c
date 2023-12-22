#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
        int x,count,left,right,temp,fd[2],fe[2];
        char c,buf[30],s[30];
        pipe(fd);
        pipe(fe);
        printf("please input a line of char:\n");
        scanf("%s",buf);
        while((x=fork())==-1);
        if(x==0){
                close(fd[0]);
                close(fe[1]);
                printf("Child Process!\n");
                write(fd[1],buf,30);
                read(fe[0],buf,30);
                printf("%s\n",buf);
                exit(0);
        }else{
                close(fd[1]);
                close(fe[0]);
                count=0;
                do{
                        read(fd[0],&c,1);
                        s[count++]=c;
                }while(c!='\0');
                printf("Parent Process!\n");
                printf("%s\n",s);count-=2;
                for(left=0,right=count;left<=count/2;left++,right--){
                        temp=s[left];
                        s[left]=s[right];
                        s[right]=temp;
                }
                write(fe[1],s,30);
                wait(0);
        }
}


