#include <iostream>
#include <vector>

using namespace std;

vector<long long> num;

int main() {

	string s;
	cin >> s;
	int length = s.size();
	for (int i = 0; i < length; i++) {
		int a=s[i] - '0';
		num.push_back(a);
	}
	
	for (int j = 0; j < length; j++) {
		int max = j;
		for (int i = 0+j; i < length; i++) {
			if (num[max] < num[i]) {
				max = i;
			}
		}
		if (max != j) {
			int temp = num[j];
			num[j] = num[max];
			num[max] = temp;
		}

	}
	for (int i = 0; i < length; i++) {
		cout << num[i];
	}
	

}