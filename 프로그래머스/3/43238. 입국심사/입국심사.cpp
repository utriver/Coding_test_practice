#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long max_time = *max_element(times.begin(),times.end());
    long long left = 1;
    long long right = max_time*(long long)n;
    
    answer = right;
    
    while(left<=right){
        long long mid = (left + right)/2;
        long long total_passed = 0;
        
        for(int i = 0;i<times.size();i++){
            total_passed += mid/times[i];
        }
        if(total_passed >=n){
            answer = mid;
            right = mid -1;
        }
        else{
            left = mid +1;
        }
        
    }
    return answer;
}