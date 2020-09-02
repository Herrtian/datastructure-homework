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
LinkList* Init_LinkList() {

	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	//ͷ��� �ǲ���������

	return list;
}

//ָ��λ�ò���
void Insert_Linklist(LinkList* list, int pos, void* data)
{
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (pos < 0 || pos > list->size)
	{
		return;
	}

	//�����µ�node
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	// ����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�½��������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;

}
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos > list->size)
	{
		return;
	}
	LinkNode* pCurrent = list->head;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ����ɾ���Ľ�� 
	LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next; //pCurrent->next->next;
	free(pDel);

	list->size--;
}
//��ȡ����
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//����(���ݵ�ַ��ע����void*)
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL) {
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}

	LinkNode* pCurrent = list->head->next;
	int i = 0;
	while (pCurrent != NULL) {
		if (pCurrent->data == data)
		{
			break;
		}
		i++;
		pCurrent = pCurrent->next;
	}

	return i;

}
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrrent = list->head->next;
	while (pCurrrent != NULL)
	{
		print(pCurrrent->data);
		pCurrrent = pCurrrent->next;
	}

}
//�ͷ��ڴ�
void FreeSpace_LinkList(LinkList* list) {

	if (list == NULL) {
		return;
	}
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		//������һ�����
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	list->size = 0;
	free(list);

}

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
	printf("ɾ�����������\n");

	Print_LinkList(list, Myprint);

	printf("��ӡ��һ�����\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);



	//��������
	FreeSpace_LinkList(list);



	system("pause");
	return 0;
}