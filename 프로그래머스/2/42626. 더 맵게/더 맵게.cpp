#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i:scoville){
        pq.push(i);
    }
    while(pq.top()<K && pq.size()>=2){
        int first = pq.top();pq.pop();
        int second = pq.top();pq.pop();
        int new_food=first+(second*2);
        pq.push(new_food);
        answer ++;
    }
    if(pq.top()<K){
        return -1;
    }
    return answer;
}