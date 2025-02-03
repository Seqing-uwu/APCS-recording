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

int maxlength(int k, string &s) {
	int n = s.size(), maxlen = 0, l = 0;
	
	while (l+k <= n) {
		// 起始區間
		string first = s.substr(l, k);
		bool isupperblock = isAllupper(first);
		bool islowerblock = isAlllower(first);
		// 不滿足直接跳過
		if (!isupperblock && !islowerblock) {
			l++;
			continue;
		}
		// 判斷交替
		int r = l;
		while (r+k <= n) {
			string b = s.substr(r, k);
			bool upper = isAllupper(b);
			bool lower = isAlllower(b);
			
			if ( (r-l) / k % 2 == 0) {
				// 偶數區間應與起始相同
				if ((isupperblock && upper) || (islowerblock && lower)) {
					r += k;
				} else 
					break;
			} else {
				// 奇數區間應與起始相反
				if ((isupperblock && lower) || (islowerblock && upper)) {
					r += k;
				} else 
					break;
			}
		}
		
		maxlen = max(maxlen, r-l);
		l++;
	}
	
	return maxlen;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	string s;
	cin >> k >> s;
	
	cout << maxlength(k, s) << "\n";
	
	return 0;
}
