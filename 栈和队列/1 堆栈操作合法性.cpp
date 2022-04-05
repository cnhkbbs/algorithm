// R7-1 堆栈操作合法性 (20 分)
// 假设以S和X分别表示入栈和出栈操作。如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。

// 输入格式:
// 输入第一行给出两个正整数N和M，其中N是待测序列的个数，M（≤50）是堆栈的最大容量。随后N行，每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。

// 输出格式:
// 对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。

// 输入样例：
// 4 10
// SSSXXSXXSX
// SSSXXSXXS
// SSSSSSSSSSXSSXXXXXXXXXXX
// SSSXXSXXX
// 输出样例：
// YES
// NO
// NO
// NO
#include<iostream>
#include<string>
using namespace std;

int Legal(string str, int m) {
	int i, flag = 0, lenth, back = 0;
	lenth = str.size();
	for (i = 0; i < lenth; i++) {
		if (str[i] == 'S') {
			flag++;
			if (flag > m) {
				break;
			}
		} else if (str[i] == 'X') {
			flag--;
			if(flag<0){
				break;
			}
		}

	}
	if (flag == 0) {
		back = 1;
	}
	return back;
}
int main() {
	int n, m, back;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		back = Legal(s, m);
		if (back == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
