#include<stdio.h>


int main()
{
	int array[10] = {1, 2, 4, 6, 8, 9, 12, 15, 149, 156};
	int brray[11] = {0};
	int m = 0;
	scanf("%d",&m);

	int pos = -1;
	if(m > 156)
	{
		for(int i = 0;i<10;i++)
		{
			brray[i] = array[i]; 
		}
		brray[10] = m;
		
		for(int i = 0;i<11;i++)
		{
			printf("%5d",brray[i]);
		}
		return 0 ;
	
	}
	
	
	for(int i = 0;i<9;i++)
	{
		if( array[i] <= m && array[i+1] >m)
		{
			pos = i;
			brray[pos+1] = m;
		} 
		
	}
	
	for(int i = 0;i<pos+1;i++)
	{
		brray[i] = array[i];
		
	}
	for(int i = pos+2 ;i<11;i++)
	{
		brray[i] = array[i-1];
	}
	if(m < 1)
	{
		brray[0] = m;
	 } 
	
	 
	 
	 
	for(int i = 0;i<11;i++)
	{
		printf("%5d",brray[i]);
	}
	
	
	
	return 0;
 } 
