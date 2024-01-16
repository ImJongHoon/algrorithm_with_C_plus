#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    int max_num = 0;
    max_num = nums.size() / 2;

    unordered_map<int, int> hash_map;

    for (auto name : nums) {
        if (hash_map.find(name) == hash_map.end()) {
            hash_map.insert({name, 1});
        }
        else {
            hash_map[name]++;
        }
    }

    if (hash_map.size() > max_num) {
        answer = max_num;
    }
    else {
        answer = hash_map.size();
    }

    return answer;
}

int main() {


    return 0;
}