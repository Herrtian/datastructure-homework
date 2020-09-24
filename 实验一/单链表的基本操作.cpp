#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结点结构体定义 
typedef struct LINKNODE{
	struct LINKNODE* next ;
	int data;
}LinkNode;

//链表结构体定义 
typedef struct LINKLIST{
	LinkNode* head;
	int size;
}Linklist;

typedef void(*PRINTNODE)(LinkNode*);

Linklist* Init_list()
{
	Linklist* list = (Linklist*)malloc(sizeof(Linklist));
	list->size = 0;
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	
	return list;
}

void List_Insert(Linklist* list,int data)
{
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = data;
	LinkNode* pCurrent = list->head;
	while(pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	node->next = pCurrent->next;
	pCurrent->next = node;
	list->size++;
}

void List_Insert_Pos(Linklist* list,int pos,int data)
{
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if(pos>list->size)
	{
		return ;
	}
	LinkNode* pCurrent = list->head;
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	for(int i = 0;i<pos;i++)
	{
		pCurrent = pCurrent->next;
	}
	node->data = data;
	node->next = pCurrent->next;
	pCurrent->next = node ;
	list->size++;
}

void List_Delete(Linklist* list,int pos)
{
	if(list == NULL)
	{
		return;
	}
	if(pos == 0 || pos> list->size)
	{
		return ;
	}
	LinkNode* pCurrent = list->head;
	for(int i = 0;i<pos-1;i++)
	{
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pCurrent->next->next;
	

}

void Print_List(Linklist* list, PRINTNODE print)  //这里使用回调函数 
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = list->head->next;
	
	
//	for(int i = 0;i<list->size - 1;i++)
//	{
//		print(pCurrent);
//		pCurrent = pCurrent->next;
//	}
	
	
	while(pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}

//  大坑！！！！ 循环链表千万不要用while 
	if(list->size == 0)
	{
		//printf("empty list!");	
	}	
}

void Myprint_Node(LinkNode* node)
{
	int p = (node->data);
	printf("%d ",p);
}

int main()
{
	Linklist* mylist = Init_list();
	int n = 0;
	scanf("%d",&n);
	for(int i = 1;i<=n ;i++)
	{
		int opt = 0;
		scanf("%d ",&opt);
		List_Insert(mylist,opt);
	}
	
	int m = 0;
	scanf("%d",&m);
	for(int i = 0;i<m;i++)
	{
		int choice ;
		scanf("%d",&choice);
		
		if(choice==0)
		{
			int s,c;
			scanf("%d %d",&s,&c);
			List_Insert_Pos(mylist,s,c);	
		}
		if(choice==1)
		{
			int s ;
			scanf("%d",&s);
			
			List_Delete(mylist,s);
		}
		
	}
	
	Print_List(mylist,Myprint_Node);	
	return 0;
}
















