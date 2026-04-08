#include <iostream>
#include <vector>

using namespace std;
int N, M;
int S[1025][1025];
int answer[100001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int in_;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> in_;
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + in_;
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		answer[i] = S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1];
	}
	for (int i = 0; i < M;i++) {
		cout << answer[i]<<"\n";
	}
}