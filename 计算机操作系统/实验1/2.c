#include <stdio.h>  
#include <sys/types.h>   
#include <unistd.h>  
  
int main()  
{  
    int p1, p2;  
    while ((p1 = fork()) == -1);      
    if (p1 == 0)     // child process 1  
    {  
        printf("b.My process ID is %d\n", getpid());  
    }  
    else  
    {  
        while ((p2 = fork()) == -1);      
        if (p2 == 0)   // child process 2  
        {  
            printf("c.My process ID is %d\n", getpid());  
        }  
        else  // parent process  
        {  
            printf("a.My process ID is %d\n", getpid());  
        }     
    }     
    return 0;     
}
