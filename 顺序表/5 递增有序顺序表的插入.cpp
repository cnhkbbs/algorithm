/*
实验目的：1、掌握线性表的基本知识 2、深入理解、掌握并灵活运用线性表。3、熟练掌握线性表的存储结构及主要运算的实现 已知顺序表L递增有序，将X插入到线性表的适当位置上，保证线性表有序。。

输入格式:
第1行输入顺序表长度，第2行输入递增有序的顺序表，第3行输入要插入的数据元素X。

输出格式:
对每一组输入，在一行中输出插入X后的递增的顺序表。

输入样例:
在这里给出一组输入。例如：

5
1 3 5 7 9
6
输出样例:
在这里给出相应的输出。例如：

1,3,5,6,7,9,*/

#include<iostream>

#define MAXSIZE 200

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int Elemtype;
typedef struct {
	Elemtype *elem;
	int length;
} Sqlist;

Sqlist L;

int InitLIst(Sqlist &L) {
	L.elem = new Elemtype[MAXSIZE];
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 0;
	return OK;
}

int ListInsert(Sqlist &L, int i, Elemtype e) {
	if ((i < 1) || (i > L.length + 1)) {
		return ERROR;
	}
	if (L.length == MAXSIZE) {
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}


int TraverseList(Sqlist &L, int i, Elemtype *p) {
	if ((i < 1) || (i > L.length + 1)) {
		return ERROR;
	}
	*p = L.elem[i - 1];
	return OK;
}

int main() 
{
	InitLIst(L);
	int n,t,m,a,b;
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>t;
		ListInsert(L,k,t);
	}
	cin>>m;
	for(int k=1;k<=n;k++){
		TraverseList(L,k,&a);
		TraverseList(L,k+1,&b);
		if(m>a&&m<b){
			ListInsert(L,k+1,m);
			break;
		}else if(m>=a&&k==n){
			ListInsert(L,k+1,m);
		}else if(m<a&&k==1){
			ListInsert(L,k,m);
		}
	}
	for(int k=1;k<=n+1;k++){
		TraverseList(L,k,&t);
		cout<<t<<",";
	}
}
