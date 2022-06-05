// 实现折半插入排序。

// 函数接口定义：
// void BInsertSort(SqList &L);
// 裁判测试程序样例：
// #include <iostream>
// #define MAXSIZE 1000
// using namespace std;

// typedef struct
// {
//  int key;
//  char *otherinfo;
// }ElemType;
                    
// typedef struct
// {
//  ElemType *r;
//  int  length;
// }SqList;

// void BInsertSort(SqList &L);
// void Create_Sq(SqList &L);//实现细节隐藏
// void show(SqList L)
// {
//  int i;
//  for(i=1;i<=L.length;i++)
//   if(i==1) 
//    cout<<L.r[i].key;
//   else
//    cout<<" "<<L.r[i].key;
// }

// int main()
// {
//  SqList L;
//  L.r=new ElemType[MAXSIZE+1];
//  L.length=0;
//  Create_Sq(L);
//  BInsertSort(L);
//  show(L);
//  return 0;
// }
// /* 请在这里填写答案 */
// 输入样例：
// 第一行输入一个数n(输入的值不大于 MAXSIZE)，接下来输入n个数。

// 7
// 24 53 45 45 12 24 90
// 输出样例：
// 输出排序结果。

// 12 24 24 45 45 53 90
////////////////////////////////////////////////
void BInsertSort(SqList &L){
	int low, high;
	for(int i=2; i<=L.length; i++){
		L.r[0] = L.r[i];
		low = 1;
		high = i-1;
		while(low <= high){
			int mid = (low+high)/2;
			if(L.r[0].key < L.r[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for(int j=i-1; j>=high+1; --j)
			L.r[j+1] = L.r[j];
		L.r[high+1] = L.r[0];
	}
}
