#include <string>
#include <vector>

using namespace std;

// DFS 함수에 현재 인덱스(depth)와 현재까지의 합(sum)을 전달합니다.
void dfs(const vector<int>& numbers, int target, int depth, int current_sum, int& answer) {
    // 1. 탈출 조건: 모든 숫자를 다 사용했을 때
    if (depth == numbers.size()) {
        if (current_sum == target) {
            answer++;
        }
        return;
    }
    
    // 2. 현재 숫자를 더하는 경우
    dfs(numbers, target, depth + 1, current_sum + numbers[depth], answer);
    
    // 3. 현재 숫자를 빼는 경우
    dfs(numbers, target, depth + 1, current_sum - numbers[depth], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    // index 0부터 시작하고, 초기 합은 0입니다.
    dfs(numbers, target, 0, 0, answer);
    return answer;
}