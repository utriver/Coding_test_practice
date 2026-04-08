#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> S;
int answer[100001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	S.resize(100001);
	cin >> N >> M;
	int in_;
	for (int i = 1; i <= N; i++) {
		cin >> in_;
		S[i] = S[i - 1] + in_;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		answer[i] = S[b] - S[a - 1];
	}
	for (int i = 0; i < M;i++) {
		cout << answer[i]<<"\n";
	}
}