#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion){
    unordered_map<string, int> hash_table;

    for (auto player : participant) {
        if (hash_table.find(player) == hash_table.end()) {
            hash_table.insert({player, 1});
        }
        else {
            hash_table[player]++;
        }
    }

    for (auto player : completion) {
        hash_table[player]--;
    }

    for (auto player : participant) {
        if (hash_table[player] > 0) {
            return player;
        }
    }
}

int main(){
    //array의 요소를 처음부터 끝까지 출력하도록 하는 반복문
    //for(자료형 요소명 : 배열명){} 으로 입력한다.
    //자료형 auto는 자료형을 직접 추론하도록 한다,

    return 0;
}