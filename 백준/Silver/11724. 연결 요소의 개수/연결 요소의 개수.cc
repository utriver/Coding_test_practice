#include <iostream>
#include <vector>

using namespace std;

int n, m; // 노드와 간선 전역변수 설정
vector<int> node[1001];
bool visited[1001];
void dfs(int cur) {
	visited[cur] = true;
	for (int next : node[cur]) {
		if (visited[next] != true) {
			dfs(next);
		}
	}

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m; //노드와 간선 수 입력 받기
	//인접리스트 제작
	for (int i = 0; i < m; i++) {
		int k, j;
		cin >> k >> j;
		node[k].push_back(j);
		node[j].push_back(k);
	}
	int count = 0;
	for (int i = 1; i < n+1; i++) {
		if (visited[i] != true) {
			dfs(i);
			count++;
		}
	}

	cout << count << "\n";

}