#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
 int min;
 int max;
}Data;
int MIN;      /* 全局变量 */


int fun1(int a[], int n) 
/*通过函数return返回最大值，通过全局变量MIN带回最小值*/
{  int i,max;
    max=MIN=a[0]; //给最大值最小值赋初值
    for (i=0;i<n;i++) 
        {
             if(a[i]>max) max=a[i];
             if (a[i]<MIN) MIN=a[i];
        }
    return(max);
}
int *fun2(int a[],int n)
/*将最大、最小值放到数组b中，通过return返回*/
{  static int b[2];
   
    int i;
  b[0]=b[1]=a[0];  //给最大值最小值赋初值
    for (i=1;i<n;i++)
        {
 if (a[i]>b[0]) b[0]=a[i];
 if (a[i]<b[1])  b[1]=a[i];
        }
    return(b);
}
Data *fun3(int a[],int n)
/*将最大、最小值放到结构体指针p中，通过return返回*/
{ 
   Data *p;
   int i;
   p=(Data *)malloc(sizeof(Data *));
   p->max=p->min=a[0];                            
   for(i=1;i<n;i++)
    {  if (a[i]>p->max)  p->max=a[i];
        if (a[i]<p->min) p->min=a[i];
    }
   return(p);
}
Data fun4(int a[],int n) 
/*将最大、最小值放到结构体p中，通过结构体p带回返回值*/
{ Data p;
 int i;
 p.max=p.min=a[0];      //给最大值最小值赋初值
 for(i=1;i<n;i++)
 {  
  if (a[i]>p.max)   p.max=a[i];
  if (a[i]<p.min)  p.min=a[i];
 }
 return(p);
}
void fun5(int a[], int n, int *p, int *q)
/*用指针带回返回值，指针p指向最大值，指针q指向最小值*/
{   int i;
     *p=*q=a[0];
     for(i=1;i<n;i++)
        {  if (*p<a[i])  *p=a[i];
            if (*q>a[i]) *q=a[i];
        }
      }
