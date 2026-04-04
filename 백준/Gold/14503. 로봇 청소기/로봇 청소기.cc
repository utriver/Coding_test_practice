#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//행,열
int N, M;
//인덱스 변수
int k;
//전체 배열, 방문배열;
int board[51][51];
bool visited[51][51];
//로봇 상태 배열
int robot[3];
//방향배열과 이동배열;

//0:북, 1: 동, 2: 남, 3: 서
int dir[] = { 0,1,2,3 };
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };
//전체 방 청소 개수
int count_=0;
void DFS(int cx, int cy, int curK);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//행,열 받기
	cin >> N >> M;
	//로봇 상태 받기
	for (int i = 0; i < 3;i++) {
		cin >> robot[i];
	}
	k = find(dir, dir+4, robot[2])-dir;
	//배열 받기-> 현재 방상태
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	DFS(robot[0],robot[1],k);
	cout << count_ << "\n";

}

//void DFS(int cx, int cy) {
//	//현재 있는 곳을 방문상태로 변환
//	if (!visited[cx][cy]) {
//		visited[cx][cy] = true;
//		count_++;
//	}
//	for (int i = 0; i < 4; i++) {
//		k --;
//		if (k < 0) k += 4;
//		else if (k > 3) k -= 4;
//		int nx = cx + dx[k];
//		int ny = cy + dy[k];
//		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//		if (visited[nx][ny] || board[nx][ny] == 1)continue;
//		DFS(nx, ny);
//	}
//	int back = (k + 2) % 4;
//	int nx = cx + dx[back];
//	int ny = cy + dy[back];
//
//	// 후진 후 범위 체크도 필요
//	if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
//	if (board[nx][ny] == 1) return;  // 후진 방향이 벽이면 종료
//	DFS(nx, ny);
//}
void DFS(int cx, int cy, int curK) {
    // 현재 칸 청소
    if (!visited[cx][cy]) {
        visited[cx][cy] = true;
        count_++;
    }

    // 4방향 왼쪽부터 탐색
    for (int i = 0; i < 4; i++) {
        curK--;
        if (curK < 0) curK += 4;
        int nx = cx + dx[curK];
        int ny = cy + dy[curK];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny] || board[nx][ny] == 1) continue;
        DFS(nx, ny, curK);  // 전진
        return;             // 전진했으면 바로 종료
    }

    // 4방향 모두 막힘 → 후진
    int back = (curK + 2) % 4;
    int nx = cx + dx[back];
    int ny = cy + dy[back];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    if (board[nx][ny] == 1) return;
    DFS(nx, ny, curK);  // 후진 (방향 유지)
}