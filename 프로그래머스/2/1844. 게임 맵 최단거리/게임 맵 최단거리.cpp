#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int BFS(int x, int y,vector<vector<int>> dist,int N,int M,vector<vector<int>> maps){
    queue<pair<int,int>> q;
    q.push({x,y});
    dist[y][x] = 1;
    vector<int> move_y = {-1,1,0,0};
    vector<int> move_x = {0,0,-1,1};
    int nx,ny;
    //int lx,ly;
    //int last_dist;
    while(!q.empty()){
        //if (lx = N-1 && ly==M-1){return last_dist;}
        auto [cx,cy] = q.front();
        q.pop();
        if (cx == M - 1 && cy == N - 1) { return dist[cy][cx]; }
        for (int i =0 ; i<4;i++){
            nx = cx+move_x[i];
            ny = cy+move_y[i];
            if(nx<0||ny<0||nx>=M || ny>=N) {continue ;}
            if(maps[ny][nx] == 0 || dist[ny][nx]>0){continue;}
            q.push({nx,ny});
            dist[ny][nx] = dist[cy][cx]+1;
            //last_dist = dist[ny][nx];
            //lx=nx;
            //ly=ny;
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int M = maps[0].size();
    int N = maps.size();
    vector<vector<int>> dist(N, vector<int>(M,0));
    answer = BFS(0,0,dist,N,M,maps);
    
    return answer;
}