#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dist[100001];

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	//BFS();
	//cout << dist[K] << "\n";
    if (N == K) { cout << 0; return 0; }  // 예외처리
    BFS();
    cout << dist[K] - 1 << "\n";  // 1부터 시작했으니 -1
}
//void BFS() {
//	queue<int> q;
//	q.push(N);
//	dist[N] = 1;
//	while (!dist[K]) {
//		int m = q.front();
//		vector<int> v1;
//		q.pop();
//		for (int i = 0; i < 3; i++) {
//			if (i == 0) {
//				int n = m * 2;
//				q.push(n);
//				dist[n] = dist[m] + 1;
//			}
//			else if (i == 1) {
//				int n = m + 1;
//				q.push(n);
//				dist[n] = dist[m] + 1;
//			}
//			else {
//				int n = m - 1;
//				q.push(n);
//				dist[n] = dist[m] + 1;
//			}
//		}
//	}
//}
void BFS() {
    queue<int> q;
    q.push(N);
    dist[N] = 1;
    while (!q.empty()) {
        int m = q.front();
        q.pop();
        int next[3] = { m * 2, m + 1, m - 1 };
        for (int i = 0; i < 3; i++) {
            int n = next[i];
            if (n < 0 || n > 100000) continue;  // 범위 체크
            if (dist[n]) continue;               // 방문 체크
            q.push(n);
            dist[n] = dist[m] + 1;
        }
    }
}