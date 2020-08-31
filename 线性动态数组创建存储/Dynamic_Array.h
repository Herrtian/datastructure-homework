#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// ��̬�����ڴ棬 ��������ݵ��ڴ�ŵ�����
// ��̬����  5��Ԫ�� �����ڴ� �������� �ͷ��ڴ� ? capacity!!
// ����capacity��ʾ�ҵ�����ڴ�ռ�һ�����Դ�Ŷ���Ԫ�� 
// size���� ��¼��ǰ�����о���Ԫ�صĸ��� 
// 

typedef struct DYNAMICARRAY {
	int* pAddr;
	int size;
	int capacity;

}Dynamic_Array;

//��ʼ�� 
Dynamic_Array* Init_Array();
//����
void PushBack_Array(Dynamic_Array* arr, int value);
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//����ֵɾ�� 
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//���� 
int Find_Array(Dynamic_Array* arr, int value);

void Print_Array(Dynamic_Array* arr);
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array* arr);
//�������
void Clear_Array(Dynamic_Array* arr);
//��ȡ��ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr);
// ��ȡ����
int Capacity_Array(Dynamic_Array* arr);
//��ȡĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos);



#endif
