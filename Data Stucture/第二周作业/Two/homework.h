#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

#define MAXSIZE 100			//顺序表可能达到的最大长度

typedef struct Book {
	char id[14];//ISBN
	char name[30];//书名
	int price;//定价
}Book;

typedef struct SqList {
	Book* elem; //存储空间的基地址
	int length; //当前长度
} SqList;

int InitList_Sq(SqList *L);
int GetElem(SqList L, int i, Book *e);
int LocateElem_Sq(SqList L, int price);
int ListInsert_Sq(SqList *L, int i, Book e);
int ListDelete_Sq(SqList *L, int i);