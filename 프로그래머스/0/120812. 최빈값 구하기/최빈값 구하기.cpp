#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    // 1. 0부터 1000까지의 숫자를 담을 수 있도록 크기를 1001로 넉넉히 잡고 함수 내부로 이동
    // (문제 조건에 따라 max_element 등을 활용할 수도 있지만 안전하게 1001로 선언)
    vector<int> mode(1001, 0);
    
    int max_count = 0; // 가장 많이 나온 빈도수
    int answer = 0;    // 최빈값 (숫자 자체)
    bool is_duplication = false; // 최빈값이 여러 개인지 확인하는 플래그

    // 2. 빈도수 카운트 (인덱스 에러 방지를 위해 입력값을 그대로 인덱스로 사용)
    for (int i : array) {
        mode[i]++;
    }

    // 3. 빈도수를 정렬하는 대신 전체를 순회하며 최빈값 찾기
    for (int i = 0; i <= 1000; i++) {
        if (mode[i] > max_count) {
            max_count = mode[i]; // 더 큰 빈도수가 나오면 갱신
            answer = i;          // 그때의 원래 숫자 저장
            is_duplication = false; // 새로운 최빈값이 나왔으므로 중복 아님으로 초기화
        } 
        else if (mode[i] == max_count && max_count > 0) {
            is_duplication = true; // 최고 빈도수와 똑같은 횟수가 또 나오면 중복 발생!
        }
    }

    // 4. 최빈값이 여러 개면 -1 리턴
    if (is_duplication) {
        return -1;
    }

    return answer;
}