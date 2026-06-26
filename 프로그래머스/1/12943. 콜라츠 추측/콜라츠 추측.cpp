#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num; 
    int count = 0; 

    if (n == 1) return 0;

    while (count < 500) {
        count++;
        
        n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
        
        if (n == 1) {
            return count;
        }
    }

    return -1;
}