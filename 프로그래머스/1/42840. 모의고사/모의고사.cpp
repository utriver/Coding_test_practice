#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> students = {{1,2,3,4,5},
                                {2,1,2,3,2,4,2,5},
                                {3,3,1,1,2,2,4,4,5,5}};

vector<int> solution(vector<int> answers) {
    //최다 득점자 백터
    vector<int> answer;
    //학생별 문제를 맞힌 숫자
    vector<int> answer_value(3,0);
    int max_value = 0;
    int answer_length = answers.size();

    // 1번학생 기준
    for (int j=0;j<3;j++){
        for(int i=0;i<answer_length;i++){
            if(answers[i]==students[j][i%students[j].size()]){
                answer_value[j]++;
            }
        }
        max_value = max(max_value,answer_value[j]);
    }

    for(int i=0;i<3;i++){
        if (answer_value[i] == max_value){
            answer.push_back(i+1);
        }
    }
    return answer;
}