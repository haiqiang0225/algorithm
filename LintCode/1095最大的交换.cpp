#include<iostream>
#include<string>
#include<sstream>
#include<stack> 
using namespace std;

int maximumSwap(int num) {
	//初始化数据 
	stringstream strS;
	string strNum;
	strS << num;
	strS >> strNum;
	strS.clear();
	strS.str("");
	
	stack<char> sta;
	int left = strNum.size();
	
	//寻找left left越小越好 
  //遍历并入栈，栈元素为数字对应的下标，如果栈顶的数字小于当前数字，那么就取出栈顶的元素，并且更新index，重复，直到栈顶的数字大于等于当前数字
	for (int i = 0; i < strNum.size(); ++i) {
		while (!sta.empty() && strNum[sta.top()] < strNum[i]) {
			int index = sta.top();
			sta.pop();
			left = min(left, index);
		}
		sta.push(i);
	}
	//寻找right right需要大于left，并且值越大越好 
	if (left < strNum.size()) {
		int right = -1;
		char max = strNum[left];
		for (int i = left; i < strNum.size(); ++i) {
			if (strNum[i] >= max) {
				right = i;
				max = strNum[i];
			}
		}
		swap(strNum[left], strNum[right]);
	}
	
	num = 0;
	strS << strNum;
	strS >> num;
	return num;
}

int main() {
	int i;
	while (cin >> i) {
		cout << maximumSwap(i) << endl;
	}	
	return 0;
} 
