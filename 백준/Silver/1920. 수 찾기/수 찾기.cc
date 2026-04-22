#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct N {
	int num=0;
	vector<int> num_array;
};
int first, last, middle;
bool finish;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	struct N n;
	struct N m;
	cin >> n.num;
	for (int i = 0; i < n.num; i++) {
		int a;
		cin >> a;
		n.num_array.push_back(a);
	}
	sort(n.num_array.begin(), n.num_array.end());


	cin >> m.num;

	for (int i = 0; i < m.num; i++) {
		int s;
		cin >> s;
		finish = false;
		first = 0;
		last = n.num - 1;
		while (first <=last)
		{
			middle = (first + last) / 2;
			if (s == n.num_array[middle]) {
				finish = true;
				cout << 1 << "\n";
				goto found;
			}


			else if (s > n.num_array[middle]) {
				first = middle + 1;
				continue;
			}
			else{
				last = middle - 1;
				continue;
			}

		}
		cout << 0 << "\n";
	found:;

	}
}