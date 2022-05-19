// 输入n值(1<=n<=1000)、n个非降序排列的整数以及要查找的数x，使用二分查找算法查找x，输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。

// 输入格式:
// 输入共三行：
// 第一行是n值；
// 第二行是n个整数；
// 第三行是x值。

// 输出格式:
// 输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。

// 输入样例:
// 4
// 1 2 3 4
// 1
// 输出样例:
// 0
// 2
//////////////////////////////////////
#include<iostream>
#define MAXSIZE 1001
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
} Sqlist;
bool InitList(Sqlist &L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) {
		return false;
	}
	L.length = 0;
	return true;
}
int main() {
	Sqlist L;
	InitList(L);
	int n, t, i, target, times = 0, flag = -1;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t;
		if (i > 1000) {
			break;
		}
		L.elem[i] = t;
		L.length++;
	}
	cin >> target;
	int low = 0;
	int hight = L.length-1;
	int mid = (low + hight) / 2;
	while (low <= hight) {
		times++;
		if (L.elem[mid] == target) {
			flag = mid;
			break;
		}
		if (L.elem[mid] > target) {
			hight = mid - 1;
			mid = (low + hight) / 2;
		} else if (L.elem[mid] < target) {
			low = mid + 1;
			mid = (low + hight) / 2;
		}
	}
	cout << flag << "\n" << times << endl;
}
