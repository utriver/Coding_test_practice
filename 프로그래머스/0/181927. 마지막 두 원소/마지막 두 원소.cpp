#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int size_lst = num_list.size();
    if (num_list[size_lst-1]>num_list[size_lst-2]){
        num_list.push_back(num_list[size_lst-1]-num_list[size_lst-2]);
    }
    else{
        num_list.push_back(2*num_list[size_lst-1]);
    }
    answer = num_list;
    return answer;
}