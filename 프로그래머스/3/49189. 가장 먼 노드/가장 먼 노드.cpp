#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void BFS(int start,  vector<vector<int>> edge_v, vector<int> &visited);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int v=edge.size();
    vector<vector<int>> edge_v;
    vector<int> visited(n+1,0);
    edge_v.resize(n+1);
    
    for (int i = 0;i<v;i++){
        edge_v[edge[i].front()].push_back(edge[i].back());
        edge_v[edge[i].back()].push_back(edge[i].front());
    }
    
    BFS(1, edge_v, visited);
    
    sort(visited.begin(), visited.end(), greater<int>());
    
    int max_value = visited.front();
    
    for(int k: visited){
        if (max_value == k){answer++;}
        else{break;}
    }
    return answer;
}

void BFS(int start,  vector<vector<int>> edge_v, vector<int> &visited){
    queue<int> q;
    q.push(start);
    visited[start]++;
    
    while(!q.empty()){
        int now_node = q.front();
        q.pop();
        for (int next:edge_v[now_node]){
            if(visited[next]==0){
                q.push(next);
                visited[next]=visited[now_node]+1;
            }
        }
    }
}