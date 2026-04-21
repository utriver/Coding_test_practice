#include <iostream>
#include <vector>

using namespace std;

int n;
int A[15];
int count_;

bool is_pos(int cur_row, int cur_col);
void dfs(int row);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs(0);
	cout << count_ << "\n";
}

void dfs(int row) {
	if (row == n) {
		count_++;
		return;
	}

	for (int i = 0; i < n; i++) {
		A[row] = i;
		if (is_pos(row,i)) {
			dfs(row + 1);
		}
	}
}

bool is_pos(int cur_row,int cur_col) {
	for (int i = 0; i < cur_row; i++) {
		if (cur_col == A[i]) 
			return false;
		if (abs(cur_row - i) == abs(cur_col - A[i]))
			return false;
	}
	return true;
}