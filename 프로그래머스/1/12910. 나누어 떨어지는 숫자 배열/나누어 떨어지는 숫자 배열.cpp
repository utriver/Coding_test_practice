#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    int i = 0;
    vector<int> new_;
    while (i < arr.size()) {
        if (arr[i] % divisor == 0) {
            new_.push_back(arr[i]);
        }

        i += 1;
    }
    if (new_.size() == 0) {
        new_.push_back(-1);
    }
    sort(new_.begin(), new_.end());

    return new_;
}