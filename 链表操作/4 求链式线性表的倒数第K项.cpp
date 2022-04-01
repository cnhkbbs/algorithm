/*
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。

输入格式:
输入首先给出一个正整数K，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:
输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。

输入样例:
4 1 2 3 4 5 6 7 8 9 0 -1
输出样例:
7
*/
#include<iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode {
	ElemType data;  //数据域
	int locate;      //位置
	struct LNode *next;  //指针域
} LNode, *LinkList;


//初始化
void InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
}

int main() {
	LinkList L;  //创建链表
	InitList(L);  //初始化
	LinkList q = L;  //复制临时起始地址 
	int k, t = 0, i, back = -1; //变量对照 k：倒数第K个 t：用于逐个存储数字串 back：用于存储查找返回情况
	 
	cin >> k;  //获得k值 
	/////////存储开始////////// 
	for (i = 1;; i++) {
		cin >> t;  //逐个获取字符串 
		if (t < 0) {
			break;  //终止信标判断 
		}
		LinkList s;   //创建新结点 
		s = new LNode;  //开辟空间 
		s->data = t;    //存入新数据 
		s->locate = i;   //位置存储
		s->next = q->next;  //将新结点连入链表 
		q->next = s;
		q=q->next;    //继续指向下一结点，为下次存入准备 
	}
	////////查找开始//////////// 
	LinkList p = L->next;  //复制临时起始地址
	 
	if (L != NULL && i >= k) {  //合法性判断 
		for (; p;) {
			if (p->locate == i - k) {
				back = p->data;   //找到目标取值 
				break;
			}
			p = p->next;  //继续指向下一结点，为下次查找准备 
		}
	}
	/////////输出开始//////////// 
	if (back == -1) {
		cout << "NULL" << endl;
	} else {
		cout << back << endl;
	}
}
