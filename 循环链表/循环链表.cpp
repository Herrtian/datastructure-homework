#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����С���
typedef struct CIRCLIELISTNODE {
	struct CIRCLIELISTNODE* next;

}CircleLinkNode;

//����ṹ��
typedef struct CIRCLELINKLIST {
	CircleLinkNode head;
	int size;
}CircleLinkList;

//��дapi����

//��ʼ������
CircleLinkList* Init_CircleLinkList() 
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	//ͷ���ָ���Լ� ͵��
	clist->head.next = &(clist->head);

	clist->size = 0;

	return clist;
}

//�Ƚϻص�
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
//��ӡ�ص�
typedef void(*PRINTNODE)(CircleLinkNode*);

//����
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos>clist->size)
	{
		pos = clist->size; //�Ѻ��ж�
	}

	//����λ�ò��ҽ��
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//������������
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;

}

//��ȡ��һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		return;
	}

	//����pos�ҽ��
	//����ָ�����

	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//���浱ǰ������һ�����
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	clist->size--;

}
//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) 
{
	if (clist == NULL)
	{
		return;
	}

	//���Ǹ�ѭ������
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = pPrev->next;
	int i = 0;
	for (i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == 1) {
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
//���������
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}
//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1 ;
	}
	CircleLinkNode* pCurrent = clist->head.next;
	int flag = -1;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == true)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}

	return flag;

}
//��ӡ���
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
	if (clist == NULL)
	{
		return;
	}
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;

	}

}
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}

	free(clist);
}
//�ж��Ƿ�Ϊ��
bool IsEmpty_CircleLinkList(CircleLinkList* clist) 
{
	if (clist->size == 0)
	{
		return false;
	}
	return true;

}

typedef struct PERSON {

	CircleLinkNode node;
	char name[64]="aaa" ;
	int age=18;
	int score=33;
}Person;

void Myprint(CircleLinkNode* data)
{
	Person* p = (Person*)data;
	printf("name:%s age: %d\n", p->name, p->age);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) {
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score)
	{
		return 1;
	}
	return 0;

}

int main()
{
	//��ʼ������
	CircleLinkList* clist = Init_CircleLinkList();
	Person p1, p2, p3, p4, p5;
	p1.age = 1;
	p2.age = 2;
	p3.age = 3;
	p4.age = 4;
	p5.age = 5;
	

	//�Ѻò���

	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p5);
	Insert_CircleLinkList(clist, 3, (CircleLinkNode*)&p5);

	
	Print_CircleLinkList(clist, Myprint);


	FreeSpace_CircleLinkList(clist);

	system("pause");

	return 0;
}
