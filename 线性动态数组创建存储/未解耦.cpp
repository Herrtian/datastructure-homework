#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMICARRAY {
	int* pAddr;
	int size;
	int capacity;

}Dynamic_Array;

//Dynamic_Array* Init_Array();
////����
//void PushBack_Array(Dynamic_Array* arr, int value);
////����λ��ɾ��
//void RemoveByPos_Array(Dynamic_Array* arr, int pos);
////����ֵɾ�� 
//void RemoveByValue_Array(Dynamic_Array* arr, int value);
////���� 
//int Find_Array(Dynamic_Array* arr, int value);
//
//void Print_Array(Dynamic_Array* arr);
////�ͷŶ�̬������ڴ�
//void FreeSpace_Array(Dynamic_Array* arr);
////�������
//void Clear_Array(Dynamic_Array* arr);
////��ȡ��ǰԪ�ظ���
//int Size_Array(Dynamic_Array* arr);
//// ��ȡ����
//int Capacity_Array(Dynamic_Array* arr);
////��ȡĳ��λ��Ԫ��
//int At_Array(Dynamic_Array* arr, int pos);


// ��̬����ĳ�ʼ��
Dynamic_Array* Init_Array() {

	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);

	return myArray;
}

void PushBack_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL) {
		return;
	}

	//�жϿռ��Ƿ��㹻
	if (arr->size == arr->capacity) {

		// ��һ�� ����һ�������ڴ�ռ�Ϊ֮ǰ������
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		// �ڶ��� �������ݵ��µĿռ�
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		// ������ �ͷžɿռ��ڴ�
		free(arr->pAddr);

		//��������
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;
	}

	//������Ԫ��
	arr->pAddr[arr->size] = value;
	arr->size++;



}

void RemoveByPos_Array(Dynamic_Array* arr, int pos) {

	if (arr == NULL) {
		return;
	}

	// �ж�λ����Ч
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}

	//ɾ��Ԫ��
	for (int i = pos; i < arr->size; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->size--;


}

void RemoveByValue_Array(Dynamic_Array* arr, int value) {

	if (arr == NULL) {
		return;
	}

	// �ҵ�ֵ��λ��
	int pos = -1;

	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}

	}
	//����λ��ɾ��

	RemoveByPos_Array(arr, pos);

}

int Find_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL) {
		return -1;
	}

	int pos = -1;
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}
	}

	// pos = -1��ʾû�ҵ�

	return pos;
}

void Print_Array(Dynamic_Array* arr) {

	if (arr == NULL) {
		return;
	}

	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");

}

void FreeSpace_Array(Dynamic_Array* arr) {

	if (arr == NULL) {
		return;
	}

	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}

	free(arr);
}

void Clear_Array(Dynamic_Array* arr) {

	if (arr == NULL) {
		return;
	}

	arr->size = 0;
	//pAddr -> �ռ�

}
//��ȡ��ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}

	return arr->size;
}
// ��ȡ����
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}

	return arr->capacity;
}
//��ȡĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos) {

	return arr->pAddr[pos];
}


void test01() {

	Dynamic_Array* myArray = Init_Array();
	printf("%d\n", Capacity_Array(myArray));
	printf("%d\n", Size_Array(myArray));
	// ����Ԫ��
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(myArray, i);
	}
	Print_Array(myArray);
	printf("%d\n", Capacity_Array(myArray));
	printf("%d\n", Size_Array(myArray));

	//ɾ��
	RemoveByPos_Array(myArray, 0);
	Print_Array(myArray);

	// ����5��λ��
	int pos = Find_Array(myArray, 5);
	printf("pos:%d\n %d\n", pos, At_Array(myArray, pos));

	FreeSpace_Array(myArray);

}

int main(void) {
	test01();

	system("pause");
	return 0;
}