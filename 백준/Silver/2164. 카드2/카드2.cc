#include <iostream>
#include <queue>
#include <vector>

using namespace std;
queue<int> q;

int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	if (N > 2) {
		for (int i = 0; i < N - 2; i++) {
			q.pop();
			const int k = q.front();
			q.pop();
			q.push(k);
		}
	}
	
	if (N >= 2) {
		q.pop();
	}
	cout << q.front();

	return 0;
}
