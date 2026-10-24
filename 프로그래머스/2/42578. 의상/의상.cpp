#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; 
    unordered_map<string, int> clothes_map;
    
   
    for (auto c : clothes) {
        clothes_map[c[1]]++;
    }
    
    for (auto pair : clothes_map) {
        answer *= (pair.second + 1);
    }
    
    return answer - 1;
}