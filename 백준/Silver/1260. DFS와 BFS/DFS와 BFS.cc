#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, V;
vector<int> adj[1001];
bool visit[1001];
int dist[1001];
vector<int> DFS;
vector<int> BFS;
void dfs(int cx);
void bfs(int cx);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);


	bfs(V);
	for (int i : DFS) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i : BFS) {
		cout << i << " ";
	}

	return 0;
}

void dfs(int cx) {
	visit[cx] = true;
	DFS.push_back(cx);
	for (int next : adj[cx]) {
		if (!visit[next]) {
			dfs(next);
		}
	}
}

void bfs(int cx) {
	queue<int> q;
	q.push(cx);
	dist[cx] = 1;
	BFS.push_back(cx);
	while (!q.empty()) {
		int x=q.front();
		q.pop();
		for (int nx : adj[x]) {
			if (dist[nx]) continue;
			q.push(nx);
			dist[nx] = dist[x] + 1;
			BFS.push_back(nx);
		}
	}
}