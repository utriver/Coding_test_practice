#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int m, n, h;
int all_count = 0;
bool not_all;
int max_ = 0;
int board[100][100][100];
int dist[100][100][100];

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<tuple<int, int,int>> q;

void dfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++){
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					dist[i][j][k] = 1;
				}
				else if (board[i][j][k] == 0) {
					all_count++;
				}
			}
		}
	}
	if (all_count == 0) {
		cout << 0 << "\n";
		return 0;
	}
	
	dfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				
				}
			}
		}
	}
	cout << max_-1 << "\n";
	return 0 ;
}


void dfs() {
	while (!q.empty()) {
		tuple<int, int, int>t = q.front(); q.pop();
		int z = get<0>(t);
		int y = get<1>(t);
		int x = get<2>(t);
		for (int d = 0; d < 6; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nz = z + dz[d];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dist[nz][ny][nx] || board[nz][ny][nx] == 1) continue;
			if (board[nz][ny][nx] == -1)continue;
			q.push({ nz,ny,nx });
			board[nz][ny][nx] = 1;
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			if (max_ < dist[nz][ny][nx]) max_ = dist[nz][ny][nx];
		}
	}

}