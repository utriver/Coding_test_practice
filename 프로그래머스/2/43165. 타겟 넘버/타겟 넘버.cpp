#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cal[2]={-1,1};

// answer를 참조자(&)로 받아서 재귀 호출 전체에서 값을 공유합니다.
void DFS(int index, int current_value, const vector<int>& numbers, int target, int& answer) {
    // 1. 기저 조건 (모든 숫자를 다 사용했을 때)
    if (index == numbers.size()) {
        if (current_value == target) {
            answer++; // 타겟 넘버를 만들었다면 방법의 수 증가
        }
        return;
    }

    // 2. 재귀 호출 (다음 숫자를 더하는 경우와 빼는 경우 두 갈래로 분기)
    DFS(index + 1, current_value + numbers[index], numbers, target, answer);
    DFS(index + 1, current_value - numbers[index], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    // 0번 인덱스부터, 현재 합계 0으로 DFS 시작
    DFS(0, 0, numbers, target, answer);
    
    return answer;
}