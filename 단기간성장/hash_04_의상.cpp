#include <string>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

//수학적 풀이: 옷 카테고리당 옷 종류 + 1을 "조합수"라고 할 때, 조합수C1 * 조합수C1 ... - 1 (모두 다 안입는 경우) 를 통해 통계적으로 풀 수 있다. + hash를 사용해보자.

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    unordered_map<string, int> hash_table;

    for (int i = 0; i < clothes.size(); i++) {
        //해당 옷 종류가 없으면
        if (hash_table.find(clothes[i][1]) == hash_table.end()) {
            hash_table[clothes[i][1]] = 1;
        }
        else {
            hash_table[clothes[i][1]]++;
        }
    }

    int cal = 1;

    for (auto category : hash_table) {
        cal = cal * (category.second+1);
    }

    cal--;
    answer = cal;

    return answer;
}

int main() {


    return 0;
}