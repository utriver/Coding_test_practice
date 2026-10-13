#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;
    for (const string& name : participant) cnt[name]++;
    for (const string& name : completion) cnt[name]--;

    for (const auto& [name, c] : cnt) {
        if (c > 0) return name;
    }
    return ""; // 여기 도달하면 안 됨
}