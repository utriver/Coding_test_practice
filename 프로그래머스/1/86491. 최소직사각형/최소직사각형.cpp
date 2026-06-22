#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> wallet(2,0);

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int count = sizes.size();
    for(int i=0;i<count;i++){
        wallet[0] = max(wallet[0],max(sizes[i][0],sizes[i][1]));
        wallet[1] = max(wallet[1],min(sizes[i][0],sizes[i][1]));
    }
   
    answer = wallet[0]*wallet[1];
    return answer;
}