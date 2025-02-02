#include<iostream>
using namespace std;

bool isAllupper(string r) {
	for (char c:r) {
		if (c >= 'a' && c <= 'z')
			return false;
	}
	return true;
} // 判斷字串r是否為全大寫

bool isAlllower(string r) {
	for (char c:r) {
		if (c >= 'A' && c <= 'Z')
			return false;
	}
	return true;
} // 判斷字串r是否為全小寫

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	string s;
	cin >> k >> s;
	
	int ans = 0; int n = s.size();
	for (int i=0; i<=n-k; i++) {
		string r = s.substr(i, k);
		int times = 0;
		
		// 判斷 r 是否為 全大寫 / 全小寫
		if (isAllupper(r)) {
			
			int n = 0;
			for (int j=0; j<=n-k-i; j+=k) {
				string r = s.substr(i+j, k);
				// 偶數區間應與起始相同
				if (n % 2 == 0) {
					if (isAllupper(r)) times++;
					else break;
				} // 反之
				else if (n % 2 == 1) {
					if (isAlllower(r)) times++;
					else break;
				}
				n++;
			}
		}
		else if (isAlllower(r)) {
			int n = 0;
			for (int j=0; j<=n-k-i; j+=k) {
				string r = s.substr(i+j, k);
				
				if (n % 2 == 0) {
					if (isAlllower(r)) times++;
					else break;
				}
				else if (n % 2 == 1) {
					if (isAllupper(r)) times++;
					else break;
				}
				n++;
			}
		}
		// 紀錄最多交替次數
		if (times > ans) {
			ans = times;
		}
	}
	
	cout << ans*k << "\n";
	
	return 0;
}