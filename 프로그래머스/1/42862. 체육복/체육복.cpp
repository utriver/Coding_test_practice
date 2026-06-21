#include <string>
#include <vector>
#include  <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> possible (n,1);
    for (int l:lost){
        --possible[l-1];

    }
    for (int r:reserve){
        ++possible[r-1];
    }
    for (int i=0;i<n;i++){
            if (possible[i-1]==2 && i>0 && possible[i]==0){
            possible[i-1]--;
            possible[i]++;
        }
        else if (possible[i+1]==2&&i<n-1 && possible[i]==0){
            possible[i+1]--;
            possible[i]++;
        }
    }
        
        
    answer = count(possible.begin(), possible.end(), 1)+count(possible.begin(), possible.end(), 2);
    
    return answer;
}