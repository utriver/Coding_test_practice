#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 상하좌우 이동을 위한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(int startX, int startY, int targetX, int targetY, int map[102][102]) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    int visited[102][102] = {0, };
    visited[startX][startY] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 목적지(아이템 위치)에 도달한 경우 (2배 스케일이므로 거리는 나중에 2로 나눠야 함)
        if(x == targetX && y == targetY) {
            return (visited[x][y] - 1) / 2;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위를 벗어나거나, 테두리가 아니거나(0인 경우), 이미 방문한 경우 건너뜀
            if(nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
            if(map[nx][ny] == 0 || visited[nx][ny] > 0) continue;
            
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 1. 좌표를 2배로 확장하므로 102x102 크기로 선언
    int map[102][102] = {0, };
    
    // 좌표 2배 스케일링 적용
    for(auto& r : rectangle) {
        int x1 = r[0] * 2;
        int y1 = r[1] * 2;
        int x2 = r[2] * 2;
        int y2 = r[3] * 2;
        
        // 직사각형 내부 전체를 1로 채움
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                map[i][j] = 1;
            }
        }
    }
    
    // 2. 다른 직사각형의 '내부(경계선 제외)'에 포함되는 곳은 0으로 지우기 (외곽선만 남김)
    for(auto& r : rectangle) {
        int x1 = r[0] * 2;
        int y1 = r[1] * 2;
        int x2 = r[2] * 2;
        int y2 = r[3] * 2;
        
        for(int i = x1 + 1; i < x2; i++) {
            for(int j = y1 + 1; j < y2; j++) {
                map[i][j] = 0; // 내부는 탐색 경로에서 제외
            }
        }
    }
    
    // 캐릭터와 아이템 위치도 2배로 변환하여 탐색 시작
    return BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2, map);
}