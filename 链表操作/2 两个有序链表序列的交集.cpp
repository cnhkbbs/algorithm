// 已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。

// 输入格式:
// 输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。

// 输出格式:
// 在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

// 输入样例:
// 1 2 5 -1
// 2 4 5 8 10 -1
// 输出样例:
// 2 5

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); 

List Intersection( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Intersection(L1, L2);
    Print(L);
    return 0;
}
List Read()
{
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	List temp = L;
	int e;
	scanf("%d",&e);
	while(e != -1)
	{
		List p = (List)malloc(sizeof(struct Node));
		p->Data = e;
		p->Next = temp->Next;
		temp->Next = p;
		temp = p;
		scanf("%d",&e);
	}
	return L;
}
void Print( List L )
{
	L = L->Next;
	if(L == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while(L->Next)
	{
		printf("%d ",L->Data);
		L = L->Next;
	}
	printf("%d\n",L->Data);
}
List Intersection( List L1, List L2 )
{
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	List temp = L;
	L1 = L1->Next;
	L2 = L2->Next;
	while(L1 && L2)
	{
		if(L1->Data == L2->Data)
		{
			temp->Next = L1;
			temp = L1;
			L1 = L1->Next;
			L2 = L2->Next;
		}
		else if(L1->Data < L2->Data)
		{
			L1 = L1->Next;
		}
		else
		{
			
		}L2 = L2->Next;
	}
	temp->Next = NULL;
	return L;
}
