#include<iostream>
using namespace std;
/**
 * 思想：
 * 使用分治技术意味着要将数组(问题)划分为尽可能相等的两个子数组(子问题)
 * 1.从中间划分为两个子数组 [a..mid]和[mid+1,b]
 * 2.最大值可能在[a..mid],[mid+1,b]或者[i..mid..j](跨越mid)之间 
 * 3.对于位于两个子数组(子问题)，使用分治的思想继续递归执行
 * 4.返回三者之间的最大值 
 */ 
//find max value between 
template<typename T>
T findMaxViaMid(T *a, int start, int mid, int end) 
{
	T curMax = a[mid];
	T sum = curMax;
	int i = mid;
	while (i-- >= start) {
		curMax += a[i];
		if (curMax > sum) {
			sum = curMax;
		}
	}
	i = mid;
	while (i++ <= end) {
		curMax += a[i];
		if (curMax > sum){
			sum = curMax;
		}
	}
	return sum;
} 

int findMaxSubArray(int *a, int start, int end) {
	if (end == start) {
		return a[start];
	}
	int mid = (start + end) / 2;
	int lmax = findMaxSubArray(a, start, mid);
	int rmax = findMaxSubArray(a, mid + 1, end);
	int mmax = findMaxViaMid(a, start, mid, end);
	
	return max(lmax,max(rmax,mmax));
}

int main() {
	//43 8..11
	int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int size = sizeof(a) / sizeof(a[0]);
	cout << findMaxSubArray(a, 0, size - 1);
} 
