// 本题要求实现简单选择排序函数，待排序列的长度1<=n<=1000。

// 函数接口定义：
// void  SelectSort(SqList L);
// 其中L是待排序表，使排序后的数据从小到大排列。
// ###类型定义：

// typedef  int  KeyType;
// typedef  struct {                      
//   KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
//   int Length;      
// }SqList;
// 裁判测试程序样例：
// #include<stdio.h>
// #include<stdlib.h>
// typedef  int  KeyType;
// typedef  struct {                      
//   KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
//   int Length;      
// }SqList;
// void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
// void  SelectSort(SqList L);
// int main()
// {
//   SqList L;
//   int i;
//   CreatSqList(&L);
//   SelectSort(L);
//   for(i=1;i<=L.Length;i++)
//    {        
//      printf("%d ",L.elem[i]);
//    }
//   return 0;
// }
// /*你的代码将被嵌在这里 */
// 输入样例：
// 第一行整数表示参与排序的关键字个数。第二行是关键字值 例如：

// 10
// 5 2 4 1 8 9 10 12 3 6
// 输出样例：
// 输出由小到大的有序序列，每一个关键字之间由空格隔开，最后一个关键字后有一个空格。

// 1 2 3 4 5 6 8 9 10 12 
/////////////////////////////////////////////////////
void SelectSort(SqList L)
{
	int t;
	for(int i=1;i<L.Length+1;++i){
		int k=i;
		for(int j=i+1;j<L.Length+1;++j){
			if(L.elem[j]<L.elem[k]){
				k=j;
			}
		}
		if(k!=i){
			t=L.elem[k];
			L.elem[k]=L.elem[i];
			L.elem[i]=t;
		}
	}
}
