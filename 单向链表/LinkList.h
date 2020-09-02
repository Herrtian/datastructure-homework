#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE {
	void* data;
	struct LINKNODE* next;

}LinkNode;

typedef struct LINKLIST
{
	LinkNode* head;
	int size;

}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

//��ʼ������
LinkList* Init_LinkList();

//ָ��λ�ò���
void Insert_Linklist(LinkList* list, int pos, void* data);
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos);
//��ȡ����
int Size_LinkList(LinkList* list);
//����
int Find_LinkList(LinkList* list, void* data);
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE);
//�ͷ��ڴ�
void FreeSpace_LinkList(LinkList* list);


#endif
