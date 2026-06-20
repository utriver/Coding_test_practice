#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    int n = commands.size();
    cout << n <<"\n";
    cout << commands[0][0]<<"\n";
    cout << commands[0][1]<<"\n";
    for(int i =0;i<n;i++){
        for (int j=commands[i][0]-1;j<commands[i][1];j++){
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());

        answer.push_back(v[commands[i][2]-1]);
        v.erase(v.begin(), v.end());
    }

    
    return answer;
}