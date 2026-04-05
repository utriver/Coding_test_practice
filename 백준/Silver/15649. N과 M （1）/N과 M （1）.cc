#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
int adj[9];
bool visit[9];
int depth = 0;

void dfs(int depth);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M ;
	
	dfs(depth);

	return 0;
}

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i <M; i++) {
			cout << adj[i] <<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			adj[depth] = i+1;
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}
	