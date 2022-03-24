// 若一个线性表L采用顺序存储结构存储，其中所有的元素为整数。设计一个算法，删除元素值在[x,y]之间的所有元素，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。

// 输入格式:
// 三行数据，第一行是顺序表的元素个数，第二行是顺序表的元素，第三行是x和y。

// 输出格式:
// 删除元素值在[x,y]之间的所有元素后的顺序表。

// 输入样例:
// 10
// 5 1 9 10 67 12 8 33 6 2
// 3 10

// 输出样例:
// 1 67 12 33 2

#include<iostream>

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int Elemtype;//定义 元素类型
//构造顺序表 定义存储结构
typedef struct {
	Elemtype *elem;
	int length;
} Sqlist;

Sqlist L;//创建名为L的顺序表

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
	int n, x, y, t;

	cin >> n;

	for (int k = 1; k <= n; k++) {
		cin >> t;
		ListInsert(L, k, t);
	}
	cin >> x >> y;

//	遍历查找删除开始
	for (int k = 1; k <= n; k++) {
		TraverseList(L, k, &t);
		if (t >= x && t <= y) {
			ListDelete(L, k);
			k--;
			n--;
		}
	}

//	遍历输出开始
	for (int k = 1; k <= n; k++) {
		TraverseList(L, k, &t);
		if (k < n) {
			cout << t << " ";
		} else {
			cout << t;
		}
	}
}
