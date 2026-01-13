#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    for(string i:arr){
        answer +=i;
    }
    return answer;
}