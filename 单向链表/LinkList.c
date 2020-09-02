#include"LinkList.h"


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
	LinkNode* pCurrent = list ->head;
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


