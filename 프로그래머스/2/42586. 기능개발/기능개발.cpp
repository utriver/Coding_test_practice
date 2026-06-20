#include <string>
#include <vector>
#include<cmath>

using namespace std;
vector<int> restday;
vector<int> performance;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len_ = progresses.size();
    for (int i =0;i<len_;i++){
        int days = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        restday.push_back(days);
    }
// 2. 배포 그룹 묶기
    int max_day = restday[0]; // 현재 배포 그룹의 기준이 되는 가장 큰 일수
    int count = 1;            // 현재 그룹에 포함된 기능의 개수

    for (int i = 1; i < len_; i++) {
        if (restday[i] <= max_day) {
            // 기준일보다 일찍 끝나면 같은 날 배포하므로 개수 추가
            count++;
        } else {
            // 기준일보다 오래 걸리는 기능을 만나면 기존 그룹 배포 후 새 그룹 시작
            answer.push_back(count);
            max_day = restday[i]; // 새로운 기준일 설정
            count = 1;            // 개수 초기화
        }
    }
    // 마지막으로 남아있는 그룹 배포
    answer.push_back(count);
    return answer;
}