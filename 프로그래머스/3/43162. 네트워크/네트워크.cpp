#include <string>
#include <vector>

using namespace std;

// DFS 함수
void dfs(int current, int n, const vector<vector<int>>& computers, vector<bool>& visited) {
    // 현재 컴퓨터 방문 처리
    visited[current] = true;
    
    // 현재 컴퓨터와 연결된 다른 컴퓨터들을 탐색
    for (int next = 0; next < n; ++next) {
        // 연결되어 있고(1) + 아직 방문하지 않았다면 탐색 진행
        if (computers[current][next] == 1 && !visited[next]) {
            dfs(next, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false); // 방문 여부를 기록할 배열
    
    for (int i = 0; i < n; ++i) {
        // 아직 방문하지 않은 컴퓨터를 발견하면, 새로운 네트워크의 시작점입니다.
        if (!visited[i]) {
            dfs(i, n, computers, visited);
            answer++; // 네트워크 개수 증가
        }
    }
    
    return answer;
}