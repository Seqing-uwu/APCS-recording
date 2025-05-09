#include <iostream>
using namespace std;

const int N = 50005;
int a[N]; // 登記每個人的好友
bool used[N]; // 標記是否被找過

int main() {
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
		used[i] = false;
	}
	
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (!used[i]) {
			int cur = i;
			while (!used[cur]) { // DFS yes
				used[cur] = true;
				cur = a[cur];
			}
			cnt ++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
