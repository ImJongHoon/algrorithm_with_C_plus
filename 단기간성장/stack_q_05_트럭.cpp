#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//다리 길이 + 기다리는 시간 + 1
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    queue<int> bridge;

    int bridge_current_weight = 0;
    int out_truck_num = 0;
    int index = 0;

    while (1) {
        //pop
        if (bridge.size() >= bridge_length) {
            if (bridge.front() != 0) {
                bridge_current_weight = bridge_current_weight - bridge.front();
                out_truck_num++;
            }
            //cout << "pop: " << bridge.front() << endl;
            bridge.pop();
        }

        //push
        if (index < truck_weights.size() && bridge_current_weight + truck_weights[index] <= weight) {
            bridge.push(truck_weights[index]);
            bridge_current_weight = bridge_current_weight + truck_weights[index];
            index++;
        }
        else {
            bridge.push(0);
        }
        //cout << "push: " << bridge.back()<<endl;
        cnt++;

        //탈출조건
        if (out_truck_num == truck_weights.size()) {
            break;
        }
    }

    answer = answer + cnt;
    cout << answer;

    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7,4,5,6 };
   
    solution(bridge_length, weight, truck_weights);
    return 0;
}