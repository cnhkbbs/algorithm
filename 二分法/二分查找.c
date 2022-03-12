/*
请实现无重复数字的升序数组的二分查找

给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

数据范围：0 \le len(nums) \le 2\times10^50≤len(nums)≤2×10 
5
  ， 数组中任意值满足 |val| \le 10^9∣val∣≤10 
9
 
进阶：时间复杂度 O(\log n)O(logn) ，空间复杂度 O(1)O(1)

输入：
[-1,0,3,4,6,10,13,14],13

返回值：
6

说明：
13 出现在nums中并且下标为 6

输入：
[],3

返回值：
-1

说明：
nums为空，返回-1  
*/
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @param target int整型 
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
int search(int* nums, int numsLen, int target ) {
    // write code here
}
//////////////////////////////////////////////////////////////////////////
int search(int* nums, int numsLen, int target ) {
	//判断传入数组内是否有元素 
    if(numsLen<=0){
		return -1;
	}
	//查找开始 
	int small=0,big=numsLen-1;
	int mid=(small+big)/2;
	for(;big>=small&&target!=nums[mid];){
		if(target>nums[mid])
		{
			small=mid+1;
			mid=(small+big)/2; 
		} else{
			big=mid-1;
			mid=(small+big)/2;
		}
	}
	if(big<small){
		mid=-1;
	}
	return mid;
}

