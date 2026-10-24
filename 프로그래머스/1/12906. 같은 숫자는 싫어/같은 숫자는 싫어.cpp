#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i]);
        if(i>0 && arr[i-1]==arr[i]){
            answer.pop_back();
        }
    }

    return answer;
}