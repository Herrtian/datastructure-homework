#include"LinkList.h"


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
	LinkNode* pCurrent = list ->head;
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


