#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min_value = *min_element(arr.begin(), arr.end());
    arr.erase(remove(arr.begin(),arr.end(),min_value),arr.end());
    if (arr.size()==0){ answer = {-1};}
    else{
        answer =arr;
    }
    return answer;
}