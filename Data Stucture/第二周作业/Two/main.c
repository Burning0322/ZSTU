#include <stdio.h>
#include <stdlib.h>
#include "homework.c"

int main() {
	SqList L;
	int i = 0, temp, a, c, choose;
	int price;
	Book e;
	FILE* f = NULL;
	char buf[256];
	char* p;
	int  n;
	//errno_t err;
	choose = -1;
	while (choose != 0) {
		printf("1. 建立\n");
		printf("2. 查看\n");
		printf("3. 查找根据位置\n");
		printf("4. 查找根据价格\n");
		printf("5. 插入（编号，书名，价格）\n");
		printf("6. 删除\n");
		printf("7. 输出\n");
		printf("0. 退出\n\n");
		printf("请选择:");
		//scanf_s("%d", &choose);
		scanf("%d", &choose);
		switch (choose) {
		case 1://创建顺序表
			if (InitList_Sq(&L))
				printf("成功建立顺序表\n\n");
			else
				printf("顺序表建立失败\n\n");
			break;
		case 2: {//顺序表信息输入
			i = 0;
			//L.elem = new Book[MAXSIZE];
			if (NULL == L.elem)
			{
				printf("表未初始化！");
				break;
			}
			L.length = 0;
			//err = fopen_s(&f, "book.txt", "r");
			f = fopen("book.txt", "r");
			//if (err != 0)
			if (f == NULL)
			{
				printf("Can not open file : 1.txt");
				return 0;
			}
			i = n = 0;
			while (fgets(buf, 256, f))
			{
				//if (n == SIZE_view) break;
				//if (NULL == fgets(buf, 256, f)) break;
				if ('\n' == buf[0]) continue;     //空行继续
				p = buf;
				//sscanf_s(p, "%s%s%d", &L.elem[n].id, 255, &L.elem[n].name, 255, &L.elem[n].price);
				sscanf(p, "%s%s%d", L.elem[n].id, L.elem[n].name, &L.elem[n].price);
				n++;
			}
			do
			{
				printf("%s %s %d\n", L.elem[i].id, L.elem[i].name, L.elem[i].price);
				i++;
			} while (i < n);
			fclose(f);
			L.length = n;
		}
				break;
		case 3://顺序表的取值
			printf("请输入一个位置用来取值：\n");
			//scanf_s("%d", &i);
			scanf("%d", &i);
			temp = GetElem(L, i, &e);
			if (temp != 0) {
				printf("查找成功\n");
				printf("第%d本图书的信息是：\n", i);
				printf("%s %s %d\n", e.id, e.name, e.price);
			}
			else
				printf("查找失败！位置超出范围\n\n");
			break;
		case 4: //顺序表的查找
			printf("请输入所要查找价格:");
			//scanf_s("%d", &price);
			scanf("%d", &price);
			temp = LocateElem_Sq(L, price);
			if (temp != 0) {
				printf("查找成功\n");
				printf("该价格对应的书名为：%s\n\n", L.elem[temp - 1].name);
			}
			else
				printf("查找失败！没有这个价格对应的书籍\n\n");
			break;
		case 5: //顺序表的插入
			printf("请输入插入的位置:\n\n");
			//scanf_s("%d", &a);
			scanf("%d", &a);
			printf("请输入书本编号:\n\n");
			//scanf_s("%s", &e.id, 14);
			scanf("%s", e.id);
			printf("请输入书名:\n\n");
			//scanf_s("%s", &e.name, 30);
			scanf("%s", e.name);
			printf("请输入价格:\n\n");
			//scanf_s("%d", &e.price);
			scanf("%d", &e.price);

			if (ListInsert_Sq(&L, a, e))
				printf("插入成功.\n\n");
			else
				printf("插入失败.\n\n");
			break;
		case 6: //顺序表的删除
			printf("请输入所要删除的书籍的位置:");
			//scanf_s("%d", &c);
			scanf("%d", &c);
			if (ListDelete_Sq(&L, c))
				printf("删除成功.\n\n");
			else
				printf("删除失败.\n\n");
			break;
		case 7: //顺序表的输出
			printf("当前图书系统信息（顺序表）读出:\n");
			for (i = 0; i < L.length; i++)
				printf("%s %s %d\n", L.elem[i].id, L.elem[i].name, L.elem[i].price);
			break;
		}
	}
	return 0;
}
