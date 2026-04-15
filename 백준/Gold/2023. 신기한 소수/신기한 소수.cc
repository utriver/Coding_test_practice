#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> answer;
int ans;
bool visited[9];

void back_tracking(int depth, int k) {
	if (depth == N) {
		answer.push_back(k);
		return;
	}

	for (int i = 1; i <= 9;i++) {
		int pol = 10 * k + i;
		int c = 0;
		for (int j = 1; j*j <= pol; j++) {
			if (pol % j == 0) {
				c++;
			}
		}
		if (c==1 && pol !=1) {
			back_tracking(depth + 1, pol);
			
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	back_tracking(0, 0);
	for (int i : answer) {
		cout << i << "\n";
	}
}
