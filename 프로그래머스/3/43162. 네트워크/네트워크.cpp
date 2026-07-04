#include <string>
#include <vector>

using namespace std;

void dfs(int current, int n, const vector<vector<int>>&computers, vector<bool>&visited){
    visited[current] = true;
    
    for(int next = 0;next<n;next++){
        if(computers[current][next]==1&&!visited[next]){
            dfs(next,n,computers,visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //방문상태 확인 배열
    vector<bool> visited(n,false);
    //컴퓨터 수 만큼 연결 상태 확인
    for (int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,n,computers,visited);
            answer++;
        }
    }
    return answer;
}