/*
读入n值及n个整数，建立顺序表并遍历输出。

输入格式:
读入n及n个整数

输出格式:
输出n个整数，以空格分隔（最后一个数的后面没有空格）。

输入样例:
在这里给出一组输入。例如：

4
-3 10 20 78
输出样例:
在这里给出相应的输出。例如：

-3 10 20 78
*/


#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using  namespace std;

typedef int Elemtype;
//构造顺序表 定义存储结构
typedef struct {
	Elemtype *elem;
	int length;
} Sqlist;
Sqlist L;
//初始化顺序表
int InitList(Sqlist &L) {
	L.elem = new Elemtype[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//插入元素
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
//遍历元素
int  TraverseList(Sqlist &L, int i, Elemtype *p) {
	if ((i < 1) || (i > L.length + 1)) {
		return ERROR;
	}
	*p = L.elem[i - 1];
	return OK;
}

int main() {
	int n, t;
	cin >> n; //获取个数
	InitList(L);//初始化

	//插入元素
	for (int k = 1; k < n + 1; k++) {
		cin >> t;
		ListInsert(L, k, t);
	}

	//遍历输出
	for (int k = 1; k < n + 1; k++) {
		TraverseList(L, k, &t);
		if (k < n) {
			cout << t << " ";
		} else {
			cout<<t; 
		}
	}
}
