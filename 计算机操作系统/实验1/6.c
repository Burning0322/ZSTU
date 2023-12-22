#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
        printf("Error occurred!\n");
    } else if (pid == 0) {
        printf("我是子进程1,进程号是%d\n", getpid());
        
        // Lock the entire process to prevent interruption
        lockf(1, 1, 0);
        
        pid_t pid1;
        pid1 = fork();
        
        if (pid1 == 0) {
            printf("我是子进程1的子进程，进程号是%d\n", getpid());
        }
        
        // Unlock the entire process after completing the tasks
        lockf(1, 0, 0);
    } else {
        printf("我是父进程,进程号是%d\n", getpid());
        pid = fork();
        
        if (pid == 0) {
            printf("我是子进程2,进程号是%d\n", getpid());
        } else {
            pid = fork();
            
            if (pid == 0) {
                printf("我是子进程3,进程号是%d\n", getpid());
            }
        }
    }
    
    return 0;
}

