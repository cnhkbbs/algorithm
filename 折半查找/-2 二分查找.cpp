// 利用二分查找找出所给出的数在数组中的下标

// 输入格式:
// 第一行输入n和m表示数组有n个数据，m表示要对m个数进行查找

// 输出格式:
// 所有输出在一行完成，行末没有多余空格和多余回车。

// 输入样例:
// 5 5
// 1 2 3 4 5
// 1 2 3 4 5
// ### 输出样例:
//
// 0 1 2 3 4
/////////////////////////////
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	map<int,int> mm;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d",&num);
		mm[num] = i;
	}
	for(int i = 0; i < m; i++) {
		int num;
		scanf("%d",&num);
		if(i==0)
			printf("%d",mm[num]);
		else
			printf(" %d",mm[num]);
	}
	return 0;
}
