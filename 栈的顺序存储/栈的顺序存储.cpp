#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//stack˳��洢

typedef struct SEQSTACK {
	void* data[1024];
	int size;
}SeqStack;


//��ʼ��ջ
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
//��ջ
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
//����ջ��Ԫ��
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
//��ջ
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

//�ж��Ƿ�Ϊ��
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
//����ջ��Ԫ�صĸ���
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

//����
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
	// ��������
	SeqStack* stack = Init_SeqStack();
	// ��������
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
		//����Ԫ��
		Person* person =  (Person*)Top_SeqStack(stack);
		printf("name:%s age:%d\n", person->name, person->age);
		//����Ԫ��
		Pop_SeqStack(stack);

	
	}
	// �ͷ��ڴ�
	Free_Stack(stack);


	return 0;
}
