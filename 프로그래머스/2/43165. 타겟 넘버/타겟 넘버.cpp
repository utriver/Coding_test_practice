#include <string>
#include <vector>
#include <iostream>


using namespace std;

void DFS(vector<int> numbers,int sum, int count, int target, int &answer){
    if (count==numbers.size()){
        if(sum == target){
            answer ++;
        }
        return;
    }
    DFS(numbers,sum-numbers[count], count+1, target, answer);
    DFS(numbers,sum+numbers[count], count+1, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int count = 0;
    DFS(numbers, 0,count, target, answer);

    return answer;
}