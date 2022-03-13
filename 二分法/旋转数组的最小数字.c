/*
描述
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

数据范围：1 \le n \le 100001≤n≤10000，数组中任意元素的值: 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
示例1
输入：
[3,4,5,1,2]

返回值：
1

示例2
输入：
[3,100,200,3]

返回值：
3

/**
 * 
 * @param rotateArray int整型一维数组 
 * @param rotateArrayLen int rotateArray数组长度
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen ) {
    // write code here
}
*/
  ///////////////////////////////////////////////////////////////////////////////
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen ) {
    int small=0,big=rotateArrayLen-1;
	int mid=(small+big)/2;
	
	for(;small<big;){
		if(rotateArray[mid]>rotateArray[big]){
			small=mid+1;
			mid=(small+big)/2;
		}else if(rotateArray[small]<rotateArray[mid]){
			big=mid-1;
			mid=(small+big)/2; 
		}else{
			big-=1;
			mid=(small+big)/2; 
		}
	}
	return rotateArray[mid];
}
