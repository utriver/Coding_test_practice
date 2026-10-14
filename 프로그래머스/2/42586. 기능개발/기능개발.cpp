#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> left_day;

    // 1. 각 작업별 완료까지 걸리는 일수 계산
    for (int i = 0; i < progresses.size(); i++) {
        int left = 100 - progresses[i];
        left_day.push_back(ceil((double)left / speeds[i]));
    }

    // 2. 첫 번째 날짜를 기준(standard)으로 설정
    int standard = left_day[0];
    int count = 1;

    // 3. 두 번째 작업부터 순회
    for (int i = 1; i < left_day.size(); i++) {
        // 기준일보다 작거나 같으면 함께 배포 가능
        if (standard >= left_day[i]) {
            count++;
        } 
        else {
            // 기준일보다 더 오래 걸리는 작업을 만나면 지금까지 쌓인 것 배포
            answer.push_back(count);
            standard = left_day[i]; // 새로운 기준일 갱신
            count = 1;              // 카운트 초기화
        }
    }
    // 마지막에 쌓인 기능들 배포 결과에 추가
    answer.push_back(count);

    return answer;
}