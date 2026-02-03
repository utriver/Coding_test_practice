#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
string new_ = "";
for (int i = 0; i < str_list.size(); i++) {
    if (str_list[i].find(ex) == string::npos) {
        new_ += str_list[i];
    }
    
}
return new_;

}