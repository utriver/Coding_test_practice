#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count = 0;
    for (int i =4;i<=n;i++){
        for (int j = 1;j<=sqrt(i);j++){
            if(i%j ==0){
                count ++;
                if(i!= j){
                    count ++;
                }
            }
        }
        if(count >=3){
            answer++;
        }
        count = 0;
    }
    return answer;
}