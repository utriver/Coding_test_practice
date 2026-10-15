#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}

int lcm (int a, int b){
    return (a*b)/gcd(a,b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int denom3 = lcm(denom1,denom2);
    int numer3 = numer1*(denom3/denom1)+numer2*(denom3/denom2);
    int common_gcd = gcd(numer3, denom3);
    
    // 3. 각각 최대공약수로 나누어 약분
    numer3 /= common_gcd;
    denom3 /= common_gcd;
    
    answer.push_back(numer3);
    answer.push_back(denom3);
    
    return answer;
}