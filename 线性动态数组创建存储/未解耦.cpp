#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMICARRAY {
	int* pAddr;
	int size;
	int capacity;

}Dynamic_Array;

//Dynamic_Array* Init_Array();
////插入
//void PushBack_Array(Dynamic_Array* arr, int value);
////根据位置删除
//void RemoveByPos_Array(Dynamic_Array* arr, int pos);
////根据值删除 
//void RemoveByValue_Array(Dynamic_Array* arr, int value);
////查找 
//int Find_Array(Dynamic_Array* arr, int value);
//
//void Print_Array(Dynamic_Array* arr);
////释放动态数组的内存
//void FreeSpace_Array(Dynamic_Array* arr);
////清空数组
//void Clear_Array(Dynamic_Array* arr);
////获取当前元素个数
//int Size_Array(Dynamic_Array* arr);
//// 获取容量
//int Capacity_Array(Dynamic_Array* arr);
////获取某个位置元素
//int At_Array(Dynamic_Array* arr, int pos);


// 动态数组的初始化
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

	//判断空间是否足够
	if (arr->size == arr->capacity) {

		// 第一步 申请一块更大的内存空间为之前的两倍
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		// 第二步 拷贝数据到新的空间
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		// 第三步 释放旧空间内存
		free(arr->pAddr);

		//更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;
	}

	//插入新元素
	arr->pAddr[arr->size] = value;
	arr->size++;



}

void RemoveByPos_Array(Dynamic_Array* arr, int pos) {

	if (arr == NULL) {
		return;
	}

	// 判断位置有效
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}

	//删除元素
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

	// 找到值的位置
	int pos = -1;

	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}

	}
	//根据位置删除

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

	// pos = -1表示没找到

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
	//pAddr -> 空间

}
//获取当前元素个数
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}

	return arr->size;
}
// 获取容量
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}

	return arr->capacity;
}
//获取某个位置元素
int At_Array(Dynamic_Array* arr, int pos) {

	return arr->pAddr[pos];
}


void test01() {

	Dynamic_Array* myArray = Init_Array();
	printf("%d\n", Capacity_Array(myArray));
	printf("%d\n", Size_Array(myArray));
	// 插入元素
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(myArray, i);
	}
	Print_Array(myArray);
	printf("%d\n", Capacity_Array(myArray));
	printf("%d\n", Size_Array(myArray));

	//删除
	RemoveByPos_Array(myArray, 0);
	Print_Array(myArray);

	// 查找5的位置
	int pos = Find_Array(myArray, 5);
	printf("pos:%d\n %d\n", pos, At_Array(myArray, pos));

	FreeSpace_Array(myArray);

}

int main(void) {
	test01();

	system("pause");
	return 0;
}