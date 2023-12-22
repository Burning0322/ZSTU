#include "stdio.h"
main()
{int i,j,k;
if (i=fork())
{j=wait();
printf("Parent Process!\n");
printf("i=%d,j=%d,k=%d\n",i,j);
}
else 
{k=getpid();
printf("Child Process!\n");
printf("i=%d,k=%d\n\n",i,k);
}
} 

