#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 动态增长内存， 将存放数据的内存放到堆上
// 动态数组  5个元素 申请内存 拷贝数据 释放内存 ? capacity!!
// 容量capacity表示我的这块内存空间一共可以存放多少元素 
// size概念 记录当前数组中具体元素的个数 
// 

typedef struct DYNAMICARRAY {
	int* pAddr;
	int size;
	int capacity;

}Dynamic_Array;

//初始化 
Dynamic_Array* Init_Array();
//插入
void PushBack_Array(Dynamic_Array* arr, int value);
//根据位置删除
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//根据值删除 
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//查找 
int Find_Array(Dynamic_Array* arr, int value);

void Print_Array(Dynamic_Array* arr);
//释放动态数组的内存
void FreeSpace_Array(Dynamic_Array* arr);
//清空数组
void Clear_Array(Dynamic_Array* arr);
//获取当前元素个数
int Size_Array(Dynamic_Array* arr);
// 获取容量
int Capacity_Array(Dynamic_Array* arr);
//获取某个位置元素
int At_Array(Dynamic_Array* arr, int pos);



#endif
