#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1e14; // 我討厭你
const int N = 200005;
long long x[N], dp[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for (int i=0; i<n; i++) {
		cin >> x[i];
	}

	sort(x, x+n);
	
	int half = k/2;
	long long cost = 0;
	
	// 計算第一組 (前k組) 距離總和 
	for (int i=0; i<k; i++) {
		cost += abs(x[i] - x[half]);
	}
	dp[0] = cost;
	
	// 滑窗
	for (int i=1; i<n-k+1; i++) {
		long long old_mid = x[i + half - 1]; // 原本的中位數
		long long new_mid = x[i + k - half - 1]; // 移動後的中位數
		cost += abs(x[i+k-1] - new_mid) - abs(x[i-1] - old_mid);
		dp[i] = cost;
	}
	
	// 找不重疊的兩區間, 使其相加最小
	long long ans = INF;
	long long min_cost = INF;
	for (int i=k; i<n-k+1; i++) { // 確保不會重疊
		min_cost = min(min_cost, dp[i-k]);
		ans = min(ans, min_cost + dp[i]);
	}
	
	cout << ans << "\n";
	return 0;
}
