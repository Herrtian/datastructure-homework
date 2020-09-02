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


	//��������
	LinkList* list = Init_LinkList();

	//
	Person p1 = { "aaa",18,100 };
	Person p2 = { "bbb",18,100 };
	Person p3 = { "ccc",18,100 };
	Person p4 = { "ddd",18,100 };
	Person p5 = { "eee",18,100 };

	//�������
	Insert_Linklist(list, 0, &p1);
	Insert_Linklist(list, 0, &p2);
	Insert_Linklist(list, 0, &p3);
	Insert_Linklist(list, 0, &p4);
	Insert_Linklist(list, 0, &p5);

	//��ӡ

	Print_LinkList(list, Myprint);

	RemoveByPos_LinkList(list, 2);
	printf("ɾ���ڶ������\n");

	Print_LinkList(list, Myprint);

	printf("��ӡ��һ�����\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);



	//��������
	FreeSpace_LinkList(list);



	system("pause");
	return 0;
}