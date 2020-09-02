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

//打印函数指针
typedef void(*PRINTLINKNODE)(void*);


//初始化链表
LinkList* Init_LinkList() {

	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	//头结点 是不保存数据

	return list;
}

//指定位置插入
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

	//创建新的node
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	// 辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//新结点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;

}
//删除指定位置的值
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

	// 缓存删除的结点 
	LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next; //pCurrent->next->next;
	free(pDel);

	list->size--;
}
//获取长度
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//查找(根据地址，注意是void*)
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
//返回第一个节点
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//打印链表节点
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
//释放内存
void FreeSpace_LinkList(LinkList* list) {

	if (list == NULL) {
		return;
	}
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		//缓存下一个结点
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
	printf("删除第三个结点\n");

	Print_LinkList(list, Myprint);

	printf("打印第一个结点\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);



	//销毁链表
	FreeSpace_LinkList(list);



	system("pause");
	return 0;
}