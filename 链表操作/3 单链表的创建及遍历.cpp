// 读入n值及n个整数，建立单链表并遍历输出。

// 输入格式:
// 读入n及n个整数。

// 输出格式:
// 输出n个整数，以空格分隔（最后一个数的后面没有空格）。

// 输入样例:
// 在这里给出一组输入。例如：

// 2
// 10 5
// 输出样例:
// 在这里给出相应的输出。例如：

// 10 5

#include<iostream>
using namespace std;
typedef int Elemtype;
typedef struct LNode {
	Elemtype data;
	struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
}

int main() {
	LinkList L;
	InitList(L);

	int n, i, t;
	cin >> n;

	LinkList p = L, s;
	for (i = 0; i < n; i++) {
		cin >> t;
		s = new LNode;
		s->data = t;
		s->next = p->next;
		p->next = s;
		p = p->next;
	}

	LinkList q = L->next;
	for (i = 0; i < n; i++) {
		t = q->data;
		if (i < n - 1) {
			cout << t << " ";
		} else {
			cout << t;
		}

		q = q->next;
	}
}
