#include <stdio.h>
#include <stdlib.h>
#include "homework.h"

Status InitList_Sq(SqList* L) { //算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L->elem = (Book*)malloc(sizeof(Book) * MAXSIZE); //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L->elem)
		exit(OVERFLOW); //存储分配失败退出
	L->length = 0; //空表长度为0
	return OK;
}

Status GetElem(SqList L, int i, Book* e) {//算法2.2　顺序表的取值
	if (i < 1 || i > L.length)
		return ERROR; //判断i值是否合理，若不合理，返回ERROR
	*e = L.elem[i - 1]; //elem[i-1]单元存储第i个数据元素
	return OK;
}

int LocateElem_Sq(SqList L, int e) { //算法2.3 顺序表的查找
	//顺序表的查找
	int i;
	for (i = 0; i < L.length; i++)
		if (L.elem[i].price == e)
			return i + 1;//查找成功，返回序号i+1
	return 0;//查找失败，返回0
}

Status ListInsert_Sq(SqList* L, int i, Book e) { //算法2.4 顺序表的插入
	//在顺序表L中第i个位置之前插入新的元素e
	//i值的合法范围是1<=i<=L.length+1
	int j;
	if ((i < 1) || (i > L->length + 1))
		return ERROR; //i值不合法
	if (L->length == MAXSIZE)
		return ERROR; //当前存储空间已满

	for (j = L->length - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j]; //插入位置及之后的元素后移
	L->elem[i - 1] = e; //将新元素e放入第i个位置
	++L->length; //表长增1
	return OK;
}

Status ListDelete_Sq(SqList* L, int i) { //算法2.5 顺序表的删除
	//在顺序表L中删除第i个元素，并用e返回其值
	//i值的合法范围是1<=i<=L.length
	int j;
	if ((i < 1) || (i > L->length))
		return ERROR; //i值不合法

	for (j = i; j <= L->length; j++)
		L->elem[j - 1] = L->elem[j]; //被删除元素之后的元素前移
	--L->length; //表长减1
	return OK;
}