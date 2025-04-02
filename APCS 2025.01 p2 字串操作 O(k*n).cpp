#include <iostream>
using namespace std;

string s;
const int N = 105;
int nxt[N];
// 兩兩互換
void op0() {
	int len = s.size();
	for (int i=0; i<len; i+=2) {
		swap(s[i], s[i+1]);
	}
}
// 兩兩字典序排
void op1() {
	int len = s.size();
	for (int i=0; i<len; i+=2) {
		if (s[i] > s[i+1]) {
			swap(s[i], s[i+1]);
		}
	}
}
// 拆成前後兩半交錯排, btw 這部分可以用指標優化, 但題目 s 不長, 所以這樣寫更直觀與不容易出錯
string op2() {
	int len = s.size();
	int mid = len/2;
	string temp = "";
	
	for (int i=0; i<mid; i++) {
		temp += s[i];
		temp += s[mid+i];
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> s >> k;
	
	int op;
	for (int i=0; i<k; i++) {
		cin >> op;
		
		if (op == 0) {
			op0();
		}
		else if (op == 1) {
			op1();
		}
		else if (op == 2) {
			s = op2();
		}
	}
	
	cout << s << "\n";
	return 0;
}
