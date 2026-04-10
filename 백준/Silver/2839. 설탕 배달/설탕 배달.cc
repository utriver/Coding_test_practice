#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int fv, th = 0;
int fv_n, th_n = 0;
int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	if (N >= 5) {
		fv = N / 5;
		fv_n = N % 5;
		switch (fv_n) {
		case 1:
			fv -= 1;
			th += 2;
			break;
		case 2:
			fv -= 2;
			th += 4;
			break;
		case 3:
			th += 1;
			break;
		case 4:
			fv -= 1;
			th += 3;
			break;
		}

		if (fv < 0) {
			cout << -1 << "\n";
		}
		else {
			cout << fv + th << "\n";
		}
	}
	else if (N ==4 ) {
		cout << -1 << "\n";
	}
	else {
		cout << 1 << "\n";
	}
	

	return 0;
}
