/*本题要求实现一个对数组进行循环左移的简单函数：一个数组a中存有n（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向左移m（≥0）个位置，即将a中的数据由（最前面的m个数循环移至最后面的m个位置）。如果还需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
输入第1行给出正整数n（≤100）和整数m（≥0）；第2行给出n个整数，其间以空格分隔。

输出格式:
在一行中输出循环左移m位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例：
8 3
1 2 3 4 5 6 7 8
输出样例：
4 5 6 7 8 1 2 3
*/


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
//删除元素
int ListDelete(Sqlist &L, int i) {
	if ((i < 1) || (i > L.length)) {
		return ERROR;
	}
	for (int j = i; j <= L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	--L.length;
	return OK;
}
//遍历元素
int TraverseList(Sqlist &L, int i, Elemtype *p) {
	if ((i < 1) || (i > L.length + 1)) {
		return ERROR;
	}
	*p = L.elem[i - 1];
	return OK;
}

int main() {
	InitLIst(L);
	int n, m, t;
	cin >> n >> m;

	for (int k = 1; k <= n; k++) {
		cin >> t;
		ListInsert(L, k, t);
	}

	//元素搬运
	for (int k = 1; k <= m; k++) {
		TraverseList(L, 1, &t); //抓取元素
		ListInsert(L, n + 1, t); //尾端插入元素
		ListDelete(L, 1); //删除抓取点元素
	}

	for (int k = 1; k <= n; k++) {
		TraverseList(L, k, &t);
		if (k < n) {
			cout << t << " ";
		} else {
			cout << t;
		}
	}
}
