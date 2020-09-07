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

//初始化链表 
LinkList* Init_Linklist()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//插入  (注意是linknode* data)利用linknode*去访问下列元素
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
	//查找插入位置   辅助指针
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//插入新结点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}
//删除
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
	//这里没必要释放了，直接改变指向就行
	pDel->next = pDel->next->next;
	list->size--;

}
//查找
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
//返回列表大小
int Size_LinkList(LinkList* list);
//打印
void Print_LinkList(LinkList* list, PRINTNODE print)
{
	if (list == NULL)
	{
		return;
	}
	//辅助指针
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;

	}
	
}
//释放链表内存
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
//回调函数的逻辑：：：：
//1.在写方法的时候 写出回调 指名类型PRINTNODE 函数名print
//2.写出typedef: typedef void(*PRINTNODE)(LinkNode*);
//3.调用函数的时候 传参数
//4.函数定义：函数（类型 LinkNode* 参数 ） 注意参数的转换


void Myprint(LinkNode* data)
{
	//由于你给了node* 类型的 我得强制转换成Person类型才行
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
	//创建链表
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

	//解释：本来是&p1 可以访问到linknode name 和age
	//但是强制转换成linknode*之后，只能访问到linknode类型的node了
	//而node又穿起来了data next
	//所以这一步本质上是缩小

	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	//打印
	Print_LinkList(list, Myprint);
	//释放内存
	//Remove_LinkList(list, 2);
	////打印
	//Print_LinkList(list, Myprint);

	Person findp;
	strcpy(findp.name, "eee");
	findp.age = 10;

	int f = Find_LinkList(list, (LinkNode*)&findp, Mycompare);
	printf("%d", f);

	FreeSpace_LinkList(list);

	return 0;
}
