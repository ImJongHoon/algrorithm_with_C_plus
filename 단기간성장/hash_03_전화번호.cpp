#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//풀이법1: 사전순 정렬이란, 유사도가 높을수록 서로 가까워지게 되는 것으로도 해석할 수 있다.
//풀이법2: hash는 검색 속도가 빠르다는 것을 이용한다. 역으로 접두어가 있는지 확인하는 것.

int solution(vector<string> phone_book)
{
    bool answer = true;

    unordered_map<string, int> hash_map;

    for (auto num : phone_book) {
        hash_map[num] = 1;
    }


    //자기 자신보다 더 작은 접두어가 있는지 찾는 과정
    for (auto num : phone_book) {
        for (int i = 1; i < num.size(); i++) {
            if (hash_map.find(num.substr(0, i)) != hash_map.end()) {
                answer = false;
                return answer;
            }
        }
    }

    return answer;
}

int main() {


    return 0;
}