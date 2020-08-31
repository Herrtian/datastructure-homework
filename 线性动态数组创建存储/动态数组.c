#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"Dynamic_Array.h"

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
	printf("pos:%d\n %d\n", pos, At_Array(myArray,pos));

	FreeSpace_Array(myArray);

}


int main(void) {
	test01();

	system("pause");
	return 0;
}
