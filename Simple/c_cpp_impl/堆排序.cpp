#include<iostream>
using namespace std;

inline int getParent(int index) {
	return (index-1) >> 1;
}

inline int leftChild(int index) {
	return (index << 1) + 1;
}
//元素下沉 
void shiftDown(int *a, int i, int len) {
	int curMax;
	int temp = a[i];
	//当前节点的<i>索引</i>为i 
	//比较[当前节点i，i的左儿子，i的右儿子]的大小，将最大的与i交换，并将i设为原来最大的索引(左右儿子中大的索引)，继续比较，否则，中断。 
	for (;leftChild(i) < len; i = curMax) {
		curMax = leftChild(i);
		while (curMax < len-1 && a[curMax] < a[curMax+1]){
			curMax++;
		}
		if (a[i] < a[curMax]) {
			swap(a[i], a[curMax]);
		} else {
			break;
		}
	}
}

void heapSort(int *a, int len) {
	int i = getParent(len);
	//建堆 
	for (; i >= 0; --i) {
		shiftDown(a, i, len);
	}
	//每次取最后一个元素与当前堆中的最大值(数组[0]号)交换，交换后调整堆，未排序数组长度标记i减1 
	for (i = len-1; i > 0; --i) {
		swap(a[0], a[i]);
		shiftDown(a, 0, i);
	}
}

int main() {
	int A[6] = {4,5,3,2,6,1};
    heapSort(A, 6);	
    for (int i : A) {
    	cout << i << " ";
	}
	return 0;
}
