#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    // long long first = times.front();
    long long first = 1;
    long long end = (long long) times.back()*n;
    long long answer = end;
    while (first <=end){
        long long mid = (first+end)/2;
        long long count = 0;
        
        for(int i:times){
            count +=(mid/i);
            if (count >= n) break;
        }

        
        if(count>=n){
            answer = mid;
            end = mid-1;
        }
        else{
            first = mid+1;
        }
    }
    return answer;
}