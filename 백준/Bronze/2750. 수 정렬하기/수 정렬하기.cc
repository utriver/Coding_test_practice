#include <iostream>
#include <vector>

using namespace std;
vector<int> num;
int c;

int main() {
	cin >> c;

	for (int i = 0; i < c; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	for (int i = 0; i < c-1;i++) {
		for (int j = 0; j < c-1-i; j++) {
			if (num[j] > num[j + 1]) {
				int tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < c; i++) {
		cout << num[i]<<"\n";
	}
}