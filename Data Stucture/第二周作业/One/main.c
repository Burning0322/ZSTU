#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main()
{
 int mData[5]={2,3,5,4,1};
//     在此处定义变量

//以下为fun1示例，仿照该示例，编写调用fun2-yy5函数，并用printf输出结果。
 int p,q;
 int rmax=fun1(mData, 5);
 int *rmax2=fun2(mData,5);
 Data *rmax3=fun3(mData,5);
 Data rmax4=fun4(mData,5);
 fun5(mData,5,&p,&q);


 printf("fun1:min1=%d,max1=%d\n",MIN,rmax);
 printf("fun2:min2=%d,max2=%d\n",rmax2[1],rmax2[0]);
 printf("fun3:min3=%d,max3=%d\n",rmax3->min,rmax3->max);
 printf("fun4:min4=%d,max4=%d\n",rmax4.min,rmax4.max);
 printf("fun5:min5=%d,max5=%d\n",p,q);

 if(rmax3!=NULL)
 {
    printf("内存释放成功\n");
    //将指针设置为空避免成为野指针
    rmax3=NULL;
 }

 //system("pause");
 exit(0);
}