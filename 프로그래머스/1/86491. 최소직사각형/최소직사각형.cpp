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
        if (sizes[i][0]>=sizes[i][1]&&wallet[0]<sizes[i][0]){
            wallet[0] = sizes[i][0];
        }
        else if(sizes[i][0]<sizes[i][1]&&wallet[0]<sizes[i][1]){
            wallet[0] = sizes[i][1];
        }
    }
    for(int i=0;i<count;i++){
        if (sizes[i][0]>=sizes[i][1] && wallet[1]<sizes[i][1]){
            wallet[1] = sizes[i][1];
        }
        else if(sizes[i][0]<sizes[i][1] && wallet[1]<sizes[i][0]){
            wallet[1] = sizes[i][0];
        }
    }
    answer = wallet[0]*wallet[1];
    return answer;
}