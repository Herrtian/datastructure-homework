
#include <iostream>
#include<malloc.h>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}LinkListNode;
 
LinkListNode* Createlist(int n)
{
    LinkListNode *head,*p,*q;
    head = (LinkListNode*)malloc(sizeof(LinkListNode));
    p = (LinkListNode*)malloc(sizeof(LinkListNode));
    head->data = 1;
    head->next = NULL;
    p = head;
    for(int i = 2;i <= n;i++)
    {
        q = (LinkListNode*)malloc(sizeof(LinkListNode));
        q->data = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    return head;
}
int main()
{
    int N,p;
    cin >> N >> p;
    int ret[N];
    int i = 0;
    LinkListNode *head,*ptr,*q;
    head = Createlist(N);
    ptr = head;
    while(i<N)
    {
        for(int j = 1;j < (p-1);j++)
        {
            ptr = ptr->next;
        }
        q = ptr->next;
        ret[i] = q->data;
        ptr->next = q->next;
        free(q);
        ptr = ptr->next;
        i++;
    }
    for(int j = 0;j<N-1;j++)
    {
        cout<<ret[j]<<' ';
    }
    cout << ret[N-1];
    return 0;
}
