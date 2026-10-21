#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 체육복 현황
    vector<int> clothes (n,1);
    for(int i: lost){clothes[i-1]--;}
    for(int j:reserve){clothes[j-1]++;}
    for(int k = 0; k<n;k++){
        if(clothes[k]>=1){
            answer ++;
        }
        else{
            if(k>0&&clothes[k-1]==2){
                clothes[k-1]--;
                clothes[k]++;
                answer++;
            }
            else if(k<n-1&& clothes[k+1]==2){
                clothes[k+1]--;
                clothes[k]++;
                answer ++;
            }
        }
    }
    return answer;
}