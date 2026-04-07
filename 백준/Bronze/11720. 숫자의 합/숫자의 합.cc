#include <iostream>

using namespace std;

int N;
int num[101];
int sum_=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		num[i]=s[i]-'0';
	}
	for (int a : num) {
		sum_ += a;
	}
	cout << sum_;
}