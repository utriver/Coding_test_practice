#include <string>
#include <vector>
#include <algorithm> // sort를 쓰기 위해 필요

using namespace std;

bool solution(vector<string> phone_book) {
    // 1. 전화번호부를 사전순으로 정렬합니다.
    sort(phone_book.begin(), phone_book.end());

    // 2. 인접한 앞뒤 번호만 딱 한 번씩만 비교합니다. (반복문 1개만 사용!)
    for (int i = 0; i < phone_book.size() - 1; i++) {
        // 뒤의 번호가 앞의 번호로 시작하는지 확인 (substr 활용)
        if (phone_book[i + 1].substr(0, phone_book[i].length()) == phone_book[i]) {
            return false; // 접두어 발견 시 바로 종료
        }
    }

    return true;
}