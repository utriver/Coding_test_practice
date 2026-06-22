#include <string>
#include <vector>

using namespace std;

// 재귀적으로 DFS를 수행할 보조 함수
int dfs(const vector<int>& numbers, int target, int idx, int sum) {
    // [종료 조건] 모든 숫자를 다 사용했을 때
    if (idx == numbers.size()) {
        // 지금까지 더하고 뺀 최종 결과(sum)가 target과 같다면 1을 반환, 아니면 0 반환
        return (sum == target) ? 1 : 0;
    }

    // [하위 탐색] 현재 숫자를 더하는 경우 + 현재 숫자를 빼는 경우
    int add_case = dfs(numbers, target, idx + 1, sum + numbers[idx]);
    int sub_case = dfs(numbers, target, idx + 1, sum - numbers[idx]);

    // 두 경우의 수의 합을 반환
    return add_case + sub_case;
}

int solution(vector<int> numbers, int target) {
    // 0번째 인덱스부터, 누적 합 0으로 시작합니다.
    return dfs(numbers, target, 0, 0);
}