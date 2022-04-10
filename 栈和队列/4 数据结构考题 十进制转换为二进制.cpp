// 利用栈（以顺序栈作存储结构）实现进制转换。给定一个十进制整数，编程将该数以二进制形式输出。

// 顺序栈的类型定义：

// #define MAXSIZE 100   // MAXSIZE为最大数据元素数目
// typedef int ElemType;
// typedef struct
// {   ElemType  *base;
//     ElemType  *top;
// }SqStack;
// 输入格式:
// 输入一个十进制整数。

// 输出格式:
// 输出转换后的二进制数。

// 输入样例:
// 15
// 输出样例:
// 在这里给出相应的输出。例如：

// 1111
//////////////////////////////////////////////////////////////////////
#include<iostream>
#define MAXSIZE 100
typedef int SElemType;
//定义存储结构
typedef struct {
	SElemType  *base;
	SElemType *top;
	int stacksize;
} SqStack;
//初始化栈
void InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE]; //分配存储空间
	S.top = S.base; //初始为空栈
	S.stacksize = MAXSIZE; //最大容量
}
//入栈
void Push(SqStack &S, SElemType e) {
	*S.top++ = e;
}
//出栈
int Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base) {
		return 404;
	}
	e = *--S.top;
	return 1;
}
using namespace std;
int main() {
	SqStack S;
	InitStack(S);

	int n, t, flag = 0;
	cin >> n;
	while (n) {
		t = n % 2;
		Push(S, t);
		n /= 2;
	}
	while (1) {
		flag = Pop(S, t);
		if (flag == 404) {
			break;
		}
		cout << t;
	}
}
