#include <iostream>
#include <queue>

using namespace std;
int n, m;
int board[100][100];
int dist[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void BFS(int cur_x, int cur_y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	BFS(0, 0);

	cout << dist[n - 1][m - 1] << "\n";

	return 0;
}
void BFS(int cur_x, int cur_y) {
	queue<pair<int, int>> q;
	q.push({ cur_x,cur_y });
	dist[cur_x][cur_y] = 1;
	while (!q.empty()) {
		pair<int, int> C = q.front();
		int x = C.first;
		int y = C.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] || board[nx][ny] == 0) continue;

			q.push({ nx,ny });
			dist[nx][ny] = dist[x][y] + 1;
		}

	}
}
