#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    // dp[i]: N을 i번 사용해서 만들 수 있는 수의 집합
    vector<unordered_set<int>> dp(9);

    for (int i = 1; i <= 8; i++) {
        // 1. 이어 붙인 숫자 넣기 (예: 5, 55, 555...)
        int base = 0;
        for (int k = 0; k < i; k++) {
            base = base * 10 + N;
        }
        dp[i].insert(base);

        // 2. 이전 집합들의 조합으로 만들기 (j와 i-j의 합이 i가 되도록)
        for (int j = 1; j < i; j++) {
            for (int x : dp[j]) {
                for (int y : dp[i - j]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x * y);
                    if (x - y > 0) dp[i].insert(x - y); // 음수 제외
                    if (y != 0) dp[i].insert(x / y);    // 0으로 나누기 제외
                }
            }
        }

        // 3. 만약 현재 i번째 집합에 number가 들어있다면 최솟값이므로 즉시 반환
        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }

    // 8번 초과해서 만들 수 없는 경우
    return -1;
}