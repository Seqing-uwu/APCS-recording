#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10069;
int l[N], r[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
	}
	// hehe
	sort(l+0, l+n);
	sort(r+0, r+n);
	
	int cur_l = l[0], cur_r = r[0];
	int p = 0, q = 0; // l[p], r[q0]
	int len = 0;
	// 線段重疊 = 合併, 不重疊 = 加長度並且跳下個線段
	while (p < n) {
		
		if (l[p] > cur_r) {
			len += cur_r - cur_l;
			// 開新的區間
			cur_l = l[p];
			cur_r = r[q];
		} else {
			// 有重疊, 更新右界
			cur_r = max(cur_r, r[q]);
		}
		p++;
		q++;
	}
	len += cur_r - cur_l; // 最後的區間
	
	cout << len << "\n";
	
	return 0;
}
