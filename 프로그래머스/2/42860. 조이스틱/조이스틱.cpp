#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    
    // 기본 좌우 이동 횟수는 오른쪽으로 쭉 가는 경우 (n - 1)
    int move = n - 1;

    for (int i = 0; i < n; i++) {
        // 1. 상하 조작 횟수 누적
        char c = name[i];
        answer += min(c - 'A', 'Z' - c + 1);

        // 2. 연속된 'A'가 끝나는 지점(next_index) 찾기
        int next_index = i + 1;
        while (next_index < n && name[next_index] == 'A') {
            next_index++;
        }


        move = min(move, i * 2 + (n - next_index));
        move = min(move, (n - next_index) * 2 + i);
    }

    answer += move;
    return answer;
}