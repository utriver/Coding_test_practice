#include <iostream>

using namespace std;

int num;
int f, l;//첫번째 숫자와 마지막 숫자
int count_=0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> num;
	f = 1; l = 1;
	int sum=0;
	while (f <= num && l <= num) {
		for (int i = f; i <= l; i++) {
			sum += i;
		}
		if (sum == num) {
			count_ += 1;
			l += 1;
			sum = 0;
		}
		else if (sum > num) {
			f += 1;
			sum = 0;
		}
		else {
			l += 1;
			sum = 0;
		}

	}
	cout << count_;

	return 0;
}
