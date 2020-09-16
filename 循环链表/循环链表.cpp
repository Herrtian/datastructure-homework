#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;

}CircleLinkNode;

typedef struct CIRCLELINKLIST {

	struct CIRCLELINKNODE head;
	int size;

}CircleLinkList;

typedef int(*COMPARE)(CircleLinkNode*, CircleLinkNode*);
typedef void(*PRINTNODE)(CircleLinkNode*);


//��ʼ������
CircleLinkList* Init_Circle() {

	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;

	return clist;
}
//���뺯��
void Insert_Data(CircleLinkList* list, int pos, CircleLinkNode* data)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 ||pos > list->size)
	{
		pos = list->size;
	}
	if (data == NULL)
	{
		return;
	}
	//����ָ�����
	CircleLinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//������������
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++ ;

}

CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) {
	return clist->head.next;
}

void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos > clist->size)
	{
		return;
	}
	
	CircleLinkNode* pDel = &(clist->head);
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pDel = pDel->next;
	}
	//����û��Ҫ�ͷ��ˣ�ֱ�Ӹı�ָ�����
	pDel->next = pDel->next->next;
	clist->size--;
}
//����ֵɾ��

void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE compare)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//�����ѭ������



	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev;
	int i = 0;
	for (i = 0; i < clist->size; i++)
	{
		
		if (compare(pCurrent, data) == 1)
		{
			pPrev->next = pCurrent->next;
			
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;

	}
	clist->size--;

}
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARE compare)
{

	int flag = -1;
	if (clist == NULL)
	{
		return flag;
	}
	if (data == NULL)
	{
		return flag;
	}
	
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == 1) {
			flag = i;
			return flag;
		}
		pCurrent = pCurrent->next;
	}

	return flag;

}
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}

	//����ָ�����
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		print(pCurrent);

		pCurrent = pCurrent->next;

	}

}

typedef struct PERSON {

	CircleLinkNode node;
	char name[64];
}Person;

void Myprint(CircleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("name : %s\n", p->name);


}

int compare(CircleLinkNode* data1, CircleLinkNode* data2)
{
	
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	if (strcmp(p1->name,p2->name) == 0 )
	{
		return 1;
	}
	return 0;
}

int main()
{
	CircleLinkList* clist = Init_Circle();

	//��������
	Person p1, p2, p3, p4, p5;
	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");
	//����������
	Insert_Data(clist, 100, (CircleLinkNode*) & (p1));
	Insert_Data(clist, 100, (CircleLinkNode*) & (p2));
	Insert_Data(clist, 100, (CircleLinkNode*) & (p3));
	Insert_Data(clist, 100, (CircleLinkNode*) & (p4));
	Insert_Data(clist, 100, (CircleLinkNode*) & (p5));

	//print
	Print_CircleLinkList(clist, Myprint);

	Person pDel;
	strcpy_s(pDel.name, "ccc");
	
	//RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)(&pDel), compare);
	Print_CircleLinkList(clist, Myprint);
	printf("-----------------------\n");
	int reet = Find_CircleLinkList(clist, (CircleLinkNode*) & (p4),compare);
	RemoveByPos_CircleLinkList(clist, reet);

	Print_CircleLinkList(clist, Myprint);


	return 0;
}
