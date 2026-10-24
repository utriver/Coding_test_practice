#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int length = p.size();
    for(int i =0;i<=t.size()-p.size();i++){
        long long a=stoll(t.substr(i,length));
        long long b=stoll(p);
        if(b>=a){
            answer++;
        }
    }
    return answer;
}