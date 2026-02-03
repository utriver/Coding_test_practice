#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
   //문자열돌면서
   int i = 0;
   int a;
   while (i < seoul.size()) {
       if (seoul[i] == "Kim") {
           a = i;
           break;
       }
       i += 1;
   }
   return "김서방은 " + to_string(a) + "에 있다";
}