#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int food: scoville){
        q.push(food);
    }
    while(q.size()>1 && q.top()<K){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            q.push(a+2*b);
            answer++;
    }
    if(q.top()<K){
        return -1;
    }
    return answer;
}