// 检查一段C语言代码的小括号( )、 中括号 [ ] 和大括号{ } 是否匹配。

// 输入格式:
// 在一行中输入一段C语言代码，长度不超过1000个字符（行末以换行符结束）。

// 输出格式:
// 第一行输出左括号的数量和右括号的数量，中间以一个空格间隔。

// 若括号是匹配的，在第二行打印YES，否则打印NO。

// 输入样例1:
// for(int i=0; i<v; i++){ visited[i] = 0; for(int j=0; j<v; j++) scanf("%d",&(g->Adj[i][j])); }
// 输出样例1:
// 8 8
// YES
// 输入样例2:
// for(int i=0; i<v; i++) a(i]=0;
// 输出样例2:
// 2 2
// NO

#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef char  SElemType;
typedef struct SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;
//初始化栈
void InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//入栈
int Push(SqStack &S, SElemType e) {
	if (S.top-S.base == S.stacksize) {
		return 0;
	}
	*S.top++ = e;
	return 1;
}
//出栈
int Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base) return 0;
	e = *--S.top;
	return 1;
}
//取栈顶元素
char GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
	return '!';
}
int main() {
	SqStack S;
	InitStack(S);  //初始化

	char zh, zhtemp;
	int lef = 0, rig = 0, flag = 1;
	while (1) {
		zh = getchar();
		if (zh == '\n') {
			break;
		}
		if (zh == '(' || zh == '{' || zh == '[') {
			lef++;
			Push(S, zh); //左括号直接入栈
		} else if (zh == ')' || zh == '}' || zh == ']') {
			rig++;
			//rig入栈合法性比对
			zhtemp = GetTop(S); //取栈顶
			if(zhtemp=='!'){ 
				flag=0;   //判断取栈顶是否成功 
			}
			if (zhtemp == '(' && (zh == ']' || zh == '}')) {
				flag = 0;
			} else if (zhtemp == '[' && (zh == ')' || zh == '}')) {
				flag = 0;
			} else if (zhtemp == '{' && (zh == ')' || zh == ']')) {
				flag = 0;
			}else{
				Pop(S,zh); //比对合法出栈 
			}
		}
	}
	if(Pop(S,zh)==1){
		flag=0; //判断是否为空栈 
	}
	cout<<lef<<" "<<rig<<endl;
	if(flag){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
