#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    phone_number.replace(0, phone_number.length() - 4, string( (phone_number.length() - 4),'*'));
    return phone_number;
}