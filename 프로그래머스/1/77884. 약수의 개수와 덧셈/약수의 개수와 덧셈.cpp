#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    /*1. for 문을 활용하여 left와 right사이의 숫자를 추출
      2. 각 숫자별 약수개수를 구함
      3. 개수가 짝수이면 +, 홀수이면 -*/ 
    //1
    for (int i=left;i<right+1;i++){
        //2. 약수개수 구하기
        //1~제곱근 n까지 만 확인
        int count = 0; // 약수 개수에 관한 변수
        for (int j = 1;j*j<=i;j++){
            if(j*j==i){
                count++;
                continue;
            }
            if (i%j == 0){
                //숫자 두개 증가
                count +=2;
            }
        }
        //약수개수를 모두 구함
        //약수개수가 짝수이면 + 홀수이면 -
    answer += (count %2 ==0) ? i:-i;
    }
    return answer;
}