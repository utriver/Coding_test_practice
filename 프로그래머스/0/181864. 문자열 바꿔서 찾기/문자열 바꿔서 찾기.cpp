#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int solution(string myString, string pat) {
    string new_ = "";
    for (int i = 0; i < myString.size(); i++) { (myString[i] == 'A') ? new_+="B" : new_+="A"; }
    // string의 c_str()을 사용하여 C 문자열로 변환
    const char* a = strstr(new_.c_str(), pat.c_str());
    if (a != NULL) {
        return 1;
    }


return 0;
    
}