#include <string>
#include <vector>
#include <unordered_map>
#include<iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> participant_map;
    for(string s:participant){
        participant_map[s]++;
    }
    for(string s:completion){
        participant_map[s]--;
    }
    for(auto pair:participant_map){
        if(pair.second >0){
            answer = pair.first;
            break;
        }
    }
    
    return answer;
}