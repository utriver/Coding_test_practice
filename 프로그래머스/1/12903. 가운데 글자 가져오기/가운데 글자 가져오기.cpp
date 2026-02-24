#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int a = s.length();
    if (a%2 !=0){
        int b= a/2;
        return answer=s.substr(b,1);
    }
    else{
        int b = a/2-1;
        return answer = s.substr(b,2);
    }


}