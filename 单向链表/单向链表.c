#define _CRT_SECURE_NO_WARININGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkList.h"

typedef struct PERSON {
	char name[64];
	int age;
	int score;
}Person;


void Myprint(void* data) {
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);

}


int main(void) {


	//创建链表
	LinkList* list = Init_LinkList();

	//
	Person p1 = { "aaa",18,100 };
	Person p2 = { "bbb",18,100 };
	Person p3 = { "ccc",18,100 };
	Person p4 = { "ddd",18,100 };
	Person p5 = { "eee",18,100 };

	//数据入表
	Insert_Linklist(list, 0, &p1);
	Insert_Linklist(list, 0, &p2);
	Insert_Linklist(list, 0, &p3);
	Insert_Linklist(list, 0, &p4);
	Insert_Linklist(list, 0, &p5);

	//打印

	Print_LinkList(list, Myprint);

	RemoveByPos_LinkList(list, 2);
	printf("删除第二个结点\n");

	Print_LinkList(list, Myprint);

	printf("打印第一个结点\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);



	//销毁链表
	FreeSpace_LinkList(list);



	system("pause");
	return 0;
}