#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE{
	char Addr[64] ;
	int data ;
	char next[64] ;	
}LinkNode; 



int main()
{
	int m = 0;
	char addr[64];
	scanf("%s %d",&addr,&m);
	
	LinkNode array[m] ;
	
	for(int i = 0;i<m;i++)
	{
		scanf("%s %d %s",&array[i].Addr,&array[i].data,&array[i].next);
	}
	
	char s[64];
	strcpy(s,addr);
	//printf("%s\n",s);
	LinkNode brray[m];
	for(int i = 0; i < m;i++)
	{
		if(strcmp(s,array[i].Addr)==0)
		{
			//printf("ok");
			brray[0] = array[i];
			break;
		}
		
	}
	
	int i = 0;
	
	while(1)
	{
		if(i == m-1)
		{
			break;
		}
		
		for(int j = 0;j<m;j++)
		{
			if(strcmp(brray[i].next,array[j].Addr) == 0)
			{
				i ++ ;
				brray[i] = array[j];
				break;
			}
			
		}
	}
	

	
	LinkNode crray[m] ;


	int k = m;
	int j = 0;
	
	for(int i = 0;i<m ;i++)
	{

		
		if(i % 2 == 0)
		{
			crray[i] = brray[k-1];
			k--;
			
		}
		if(i % 2 == 1)
		{

			crray[i] = brray[j];
			j++;
		}	
	}
	

	for(int i = 0;i<m;i++)
	{	
		if(i == m)
		{
			break;
		}
		strcpy(crray[i].next,crray[i+1].Addr);
	}
	
	strcpy(crray[m-1].next,"-1");
		

	for(int i = 0;i< m ;i++)
	{
		printf("%s %d %s\n",crray[i].Addr,crray[i].data,crray[i].next);
	}

	return 0;
}



























 
 
