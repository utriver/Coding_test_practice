#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> coin;
int coin_num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//동전의 종류
	// 1->5->10->50->100->500
	// 2로 나눴을때 몫 만큼 10을 곱해준다.
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		coin.push_back(c); 
	}
	sort(coin.begin(), coin.end(), greater<>());
	int remain = K;
	for (int a : coin) {
		if (a > remain) {
			continue;
		}
		if (a <= remain) {
			//나눈다
			int temp = remain / a;
			coin_num += temp;
			if (remain % a == 0) {
				cout << coin_num << "\n";
				break;
			}
			else {
				remain = remain % a;
			}
			//나눈 몫을 더한다
			//나머지를 확인한다
			//나머지가 있으면 pass
		}
	}
	// 나머지로 판별해서 나머지가 0이면 1, 1이면 5이다
	//동전 배열은 coin으로 한다.
	//가격과 동전 비교
	/*
	1. 동전이 가격보다 크다 -> pass
	2. 동전이 가격보다 작거나 같다 -> 나눈다 (이때 몫을 카운트 변수에 더한다.
	*/
	//나눈후
	/*
	1. 나눈 후에 나머지가 0이 아니면 다시 가격과 동전을 비교한다
	2. 나머지가 0이면 카운트 변수를 출력하고 종료한다.


	*/
	
}