#include <vector>
#include <iostream>

using namespace std;
vector<int> v;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (int i =0;i<arr.size();i++){
        if (v.empty()){
            v.push_back(arr[i]);
        }
        else if (v.back()!=arr[i]){
            v.push_back(arr[i]);
        }
    }
    answer = v;

    return answer;
}