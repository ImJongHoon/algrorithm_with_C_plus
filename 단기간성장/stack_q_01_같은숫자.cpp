#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int temp = -1;

    for (auto num : arr) {
        if (temp == num) {
            
        }
        else {
            answer.push_back(num);
            temp = num;
        }
    }

    return answer;
}

int main() {


    return 0;
}