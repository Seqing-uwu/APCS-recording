#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, n;
	cin >> a >> b >> n;
	
	int round = a + b;
	int seconds = 0;
	
	int t;
	for (int i=0; i<n; i++) {
		cin >> t;
		int s = t % round;
		if (s >= a) { // 是否為紅燈
			seconds += round - s;
		}
	}
	
	cout << seconds << "\n";
	return 0;
}
