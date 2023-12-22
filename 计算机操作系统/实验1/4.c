#include <stdio.h>  
#include <unistd.h>  
  
int main()  
{  
    int pl, p2, i;  
    while ((pl = fork()) == -1);  
    if (pl == 0) {  
        for (i = 0; i < 50000; i++) {  
            printf("son %d\n", i);  
        }  
    } else {  
        while ((p2 = fork()) == -1);  
        if (p2 == 0) {  
            for (i = 0; i < 50000; i++) {  
                printf("daughter %d\n", i);  
            }  
        } else {  
            for (i = 0; i < 50000; i++) {  
                printf("parent %d\n", i);  
            }  
        }  
    }  
    return 0;  
}
