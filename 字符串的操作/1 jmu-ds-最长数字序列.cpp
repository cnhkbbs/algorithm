// 输入一个字符串，求该字符串中最长连续数字序列出现的起始位置及其长度。

// 输入格式:
// 输入一个字符串，可包含空格。

// 输出格式:
// 输出内容：最长数字序列起始位置和长度空格隔开。输出尾部不能有空格。输入空串，输出"NULL"

// 输入样例:
// 123ab12345a
// 输出样例:
// 5 5
////////////////////////////////////////////////////
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int maxs = 0, flag = 1, i, locate, tlocate, count = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '1' && str[i] <= '9') {
			if (flag) {
				tlocate = i;
				flag = 0;
			}
			count++;
		}
		if (str[i + 1] > '9' || str[i + 1] < '1') {
			if (count > maxs) {
				maxs = count;
				locate = tlocate;
			}
			count = 0;
			flag = 1;
		}
	}
	if (maxs > 0) {
		cout << locate << " " << maxs;
	} else {
		cout << "NULL";
	}

}
