#include<iostream>
#include<set>
using namespace std;

//求最小公约数
//假设 c 是 a,b 的最小公约数 那么a，b的最小公倍数为 a * b / c; 
int gcd(int a, int b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	else return gcd(b, a % b);
}

int main() {
	//每个组加班的人数 
	int a, b, c;
	cin >> a >> b >> c;
	set<int> result;
	result.insert(a * b / gcd(a, b) ); 
	result.insert(a * c / gcd(a, c) );
	result.insert(b * c / gcd(b, c) );
	
	for (set<int>::iterator it = result.begin(); it != result.end(); ++it) {
		int t = *it;
		if (t % a == 0 && t % b == 0 && t % c == 0){
			cout << t;
		}
	}
	return 0;
} 
