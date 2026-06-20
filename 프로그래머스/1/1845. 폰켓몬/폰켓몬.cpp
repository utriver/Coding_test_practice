#include <vector>
#include <iostream>
using namespace std;
int typelist[2000001] = {0};

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size() / 2;
    for (int i:nums){
        if (typelist[i]==0){
            typelist[i] =1;
        }
    }
    int typenum=0;
    for (int k:typelist){
        if(k!=0){
            ++typenum;
        }
    }
    
    if (typenum < N){
        answer = typenum;
    }
    else{
        answer = N;
    }
    return answer;
}