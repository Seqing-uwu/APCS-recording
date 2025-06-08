#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int S = 25;
int board[S][S];
bool uesd[S][S];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct node{
	int x, y, dis;
};

int h, w;
int r, c, t, x;

void shader() {
	memset(uesd, 0, sizeof(uesd));
	queue<node> q;
	q.push({r, c, 0});
	uesd[r][c] = true;
	board[r][c] += x;
	
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		
		if (now.dis >= t) continue;
		
		for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nd = now.dis + 1;

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !uesd[nx][ny]) {
                uesd[nx][ny] = true;
                board[nx][ny] += x;
                q.push({nx, ny, nd});
            }
        }
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> h >> w >> n;
	
	for (int i=0; i<n; i++) {
		
		cin >> r >> c >> t >> x;
		shader();
	}
	
	for (int i=0; i<h; i++) {
		cout << board[i][0];
		for (int j=1; j<w; j++) {
			cout << " " << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}
