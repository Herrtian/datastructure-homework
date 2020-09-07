#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST {
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);
typedef int(*COMPARE)(LinkNode*, LinkNode*);

//��ʼ������ 
LinkList* Init_Linklist()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//����  (ע����linknode* data)����linknode*ȥ��������Ԫ��
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}
	//���Ҳ���λ��   ����ָ��
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½��
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}
//ɾ��
void Remove_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		return;
	}

	LinkNode* pDel = &(list->head);
	int i = 0;
	for ( i = 0; i < pos; i++)
	{
		pDel = pDel->next;
	}
	//����û��Ҫ�ͷ��ˣ�ֱ�Ӹı�ָ�����
	pDel->next = pDel->next->next;
	list->size--;

}
//����
int Find_LinkList(LinkList* list, LinkNode* data,COMPARE Compare)
{
	if (list == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	LinkNode* pCurrent = list->head.next ;

	for (int i = 0; i < list->size; i++)
	{
		if (Compare(pCurrent,data)==1)
		{
			return i;
		}
		pCurrent = pCurrent->next;
	}

	return -1;
}
//�����б��С
int Size_LinkList(LinkList* list);
//��ӡ
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
	{
		return;
	}
	//����ָ��
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;

	}
	
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
}

typedef struct PERSON
{
	LinkNode node;
	char name[64];
	int age;

}Person;
//�ص��������߼���������
//1.��д������ʱ�� д���ص� ָ������PRINTNODE ������print
//2.д��typedef: typedef void(*PRINTNODE)(LinkNode*);
//3.���ú�����ʱ�� ������
//4.�������壺���������� LinkNode* ���� �� ע�������ת��


void Myprint(LinkNode* data)
{
	//���������node* ���͵� �ҵ�ǿ��ת����Person���Ͳ���
	Person* p = (Person*)data;
	printf("%s %d \n", p->name, p->age);

}
int Mycompare(LinkNode* data1, LinkNode* data2)
{
	
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;

	if (strcmp(p1->name, p2->name)== 0 && (p1->age == p2->age))
	{
		return 1;
	}
	else
	{
		return 0;
	}


}


int main()
{
	//��������
	LinkList* list = Init_Linklist();

	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 10; 
	p3.age = 10;
	p4.age = 10;
	p5.age = 10;

	//���ͣ�������&p1 ���Է��ʵ�linknode name ��age
	//����ǿ��ת����linknode*֮��ֻ�ܷ��ʵ�linknode���͵�node��
	//��node�ִ�������data next
	//������һ������������С

	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	//��ӡ
	Print_LinkList(list, Myprint);
	//�ͷ��ڴ�
	//Remove_LinkList(list, 2);
	////��ӡ
	//Print_LinkList(list, Myprint);

	Person findp;
	strcpy(findp.name, "eee");
	findp.age = 10;

	int f = Find_LinkList(list, (LinkNode*)&findp, Mycompare);
	printf("%d", f);

	FreeSpace_LinkList(list);

	return 0;
}
