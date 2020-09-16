#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//stack顺序存储

typedef struct SEQSTACK {
	void* data[1024];
	int size;
}SeqStack;


//初始化栈
SeqStack* Init_SeqStack()
{
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < 1024; i++)
	{
		stack->data[i] = NULL;
	}
	
	stack->size = 0;
	return stack;
	
}
//入栈
void Push_SeqStack(SeqStack* stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}

	if (stack->size == 1024)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	stack->data[stack->size] = data;
	stack->size++;

}
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size-1];

}
//出栈
void Pop_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}

	stack->data[stack->size - 1] = NULL;
	stack->size--;
}

//判断是否为空
int IsEmpty(SeqStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->size == 0)
	{
		return 1;
	}
	if (stack->size != 0)
	{
		return 0;
	}

}
//返回栈中元素的个数
int Size_SeqStack(SeqStack* stack)
{
	return stack->size;
}
void Clear_SeqStack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i < stack->size; i++)
	{
		stack->data[i] = NULL;
	}

	stack->size = 0;
}

//销毁
void Free_Stack(SeqStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}

typedef struct PERSON {
	char name[64];
	int age;
}Person;


int main()
{
	// 测试数据
	SeqStack* stack = Init_SeqStack();
	// 创建数据
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	while (Size_SeqStack(stack) > 0)
	{
		//访问元素
		Person* person =  (Person*)Top_SeqStack(stack);
		printf("name:%s age:%d\n", person->name, person->age);
		//弹出元素
		Pop_SeqStack(stack);

	
	}
	// 释放内存
	Free_Stack(stack);


	return 0;
}
