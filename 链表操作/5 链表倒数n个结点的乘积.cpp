// 本题要求计算单链表倒数n个结点的乘积。例如，给出单链表1 2 3 4 5，则倒数2个结点的乘积为20。

// 输入格式:
// 输入有2行，第一个行为2个非负整数m和n。其中m为链表结点个数，n为链表倒数结点的数量。题目保证计算结果在int范围内。
// 第二行为链表的m个数，以空格分隔。

// 输出格式:
// 在一行中输出倒数n个结点的乘积。

// 输入样例:
// 5 2
// 1 2 3 4 5
// 输出样例:
// 20

#include<iostream>
using namespace std;

typedef int Elemtype;
typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
	L=new LNode;;
	L->next=NULL;
}

int ElemFun(LinkList &L,int m,int n){
	LinkList q=L->next;
	int j=0,result=1;
	if(n>0){
	for(;j<m;j++)
		{
			if(j>=m-n){
				result*=q->data;
			}
			q=q->next;
		}	
	}else{
		result=0;
	}
	
	return result;
}
int main()
{
	LinkList L;//建立链表L
	InitList(L);//初始化L
	
	int m,n;
	cin>>m>>n;
	
	//////////插入/////////////
	int i,t;
	LinkList p=L,s;
	for(i=0;i<m;i++)
	{
		cin>>t;
		s=new LNode;
		s->data=t;
		s->next=p->next;
		p->next=s;
		p=p->next;		
	} 
	/////输出结果/////
	cout<<ElemFun(L,m,n); 
	
}
