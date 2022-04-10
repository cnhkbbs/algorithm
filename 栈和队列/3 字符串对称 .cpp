// 编写一个算法利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同。

// 输入格式:
// 输入一个无空格的字符串。

// 输出格式:
// 如果该字符是对称的，输出yes，否则输出no。

// 输入样例:
// 在这里给出一组输入。例如：

// abba
// 输出样例:
// 在这里给出相应的输出。例如：

// yes
// 输入样例:
// 在这里给出一组输入。例如：

// abcd
// 输出样例:
// 在这里给出相应的输出。例如：

// no

////////////////////////////////////////////////////////
#include<iostream>
#define MAXSIZE 100
typedef char SElemType;
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
void Pop(SqStack &S, SElemType &e) {
	e = *--S.top;
}
//读栈顶
SElemType GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
	return '!';
}
using namespace std;
int main() {
	SqStack S;
	InitStack(S);

	char t, cop;
	t = getchar();
	Push(S, t);
	while (1) {
		t = getchar();
		if (t > 'z' || t < 'a') {
			break;
		}
		cop = GetTop(S);
		if (cop == t) {
			Pop(S, cop);
		} else {
			Push(S, t);
		}
	}
	cop = GetTop(S); //判断是否为空栈
	if (cop != '!') {
		cout << "no" << endl;
	} else {
		cout << "yes" << endl;
	}
}
