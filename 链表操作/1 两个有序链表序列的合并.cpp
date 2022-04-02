// 已知两个非降序链表序列S1与S2，设计函数构造出S1与S2合并后的新的非降序链表S3。

// 输入格式:
// 输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。

// 输出格式:
// 在一行中输出合并后新的非降序链表，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

// 输入样例:
// 1 3 5 -1
// 2 4 6 8 10 -1
// 输出样例:
// 1 2 3 4 5 6 8 10

#include<bits/stdc++.h>
using namespace std; 

typedef struct LNode{
	int Data;
	struct LNode* Next;
}*LinkList;
LinkList CreatList() 
{
	LinkList head=NULL,p,tail=NULL;
	p=new LNode;
	cin>>p->Data;
	while(p->Data!=-1)
	{
		if(!head)
		{
			head=p;
			p->Next=NULL;
		}
		if(tail)
		    tail->Next=p;
		tail=p;
		tail->Next=NULL;
		p=new LNode;
		cin>>p->Data;
	}
	return head;
}
void Print(LinkList L)
{
	if(!L)
	{
		cout<<"NULL"<<endl;
		return ;
	}
	while(L->Next)
	{
		cout<<L->Data<<" ";
		L=L->Next;
	}
	cout<<L->Data<<endl;
}

LinkList MergeList(LinkList List1,LinkList List2)
{
	LinkList l1=List1,head=NULL,l2=List2,p;
	if(!List1)
		return List2;
	if(!List2)
	    return List1;
	if(List1->Data<List2->Data)
	{
		l1=List1->Next;
		head=List1;
	}
	else{
		l2=List2->Next;
		head=List2;
	}
	p=head;
	while(l1&&l2)
	{
		if(l1->Data<l2->Data)
		{
			p->Next=l1;
			l1=l1->Next;
		}
		else{
			p->Next=l2;
			l2=l2->Next;
		}
		p=p->Next;
	}
	if(l1)
	p->Next=l1;
	if(l2)
	p->Next=l2;
	return head;
}
int main()
{
	LinkList S1,S2;
	S1=CreatList();
	S2=CreatList();
	S1=MergeList(S1,S2);
	Print(S1);
} 
