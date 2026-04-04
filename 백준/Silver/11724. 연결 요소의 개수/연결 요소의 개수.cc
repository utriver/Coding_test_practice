#include <iostream>
#include <vector>

using namespace std;
int N, M;
int count_ = 0;
vector<int> adj[1001];
bool visit[1001];
void dfs(int a);
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int k, s;
		cin >> k >> s;
		adj[k].push_back(s);
		adj[s].push_back(k);
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			count_++;
			dfs(i);
		}
	}
	cout << count_ << "\n";
}

void dfs(int a) {
	visit[a] = true;
	for (int next : adj[a]) {
		if (!visit[next]) {
			dfs(next);
		}
	}
}