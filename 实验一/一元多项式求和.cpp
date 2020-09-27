#include<iostream>
using namespace std;
#include<list>
#include<algorithm>
#include<string>

typedef struct PERSON{
	int index ; 
	int coef ;
}Person; 

//指定规则
bool comparePerson(Person &p1, Person &p2)
{
	
	return p1.index > p2.index;
} 


void printList(list<Person>&L)
{
	for(list<Person>::iterator it = L.begin(); it!= L.end();it++)
	{
		list<Person>::iterator s = it ;
		++s ;
		if(s == L.end())
		{
			cout<< it->coef << " "<<it->index;
			return ;
		}
		
		cout<< it->coef << " "<<it->index;
		cout<<" ";
	}
	
	
}

void Listadd(list<Person>&L1,list<Person>&L2)
{
	for(list<Person>::iterator it = L2.begin(); it!=L2.end(); it++)
	{
		L1.push_back(*it);
		//p1.push_back(p2)
	}
	
}

int main()
{
	int m ;
	cin >> m ;
	Person array[m] ;
	list<Person>p1 ;
	
	for(int i = 0 ;i < m ;i++)
	{
		cin >> array[i].coef >>array[i].index ;
		p1.push_back(array[i]);
	}
	
	int n ;
	cin >> n ;
	Person brray[n] ;
	list<Person>p2 ;
	
	for(int i = 0 ;i < n ;i++)
	{
		cin >> brray[i].coef >>brray[i].index ;
		p2.push_back(brray[i]);
	}
	
	Listadd(p1,p2);
	
	p1.sort(comparePerson);
		
	for(list<Person>::iterator it = p1.begin();it != p1.end();it++ )
	{
		list<Person>::iterator s = it ;
		++s ;
		
		if(it->index== s->index)
		{
			//cout<<" it: "<<it->index<<" "<<it->coef <<" s: "<<s->index<<" "<<s->coef<<"in"<<endl;
			it->coef = it->coef + s->coef ;
			if(it->coef == 0)
			{
				it = p1.erase(s);
			 } 
			it = p1.erase(s);
		}
	}
	printList(p1);	
	return 0;
}

