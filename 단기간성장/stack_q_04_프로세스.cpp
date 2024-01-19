#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//숫자가 큰게 우선순위가 큼
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    priority_queue<int> pq;
    int prosessNum = priorities.size();
    int current_location = location;

    for (auto pr : priorities) {
        q.push(pr);
        pq.push(pr);
    }

    int cnt = 0;
    int temp;
    while(1){
        if (pq.top() == q.front() && current_location == 0) {
            cout << "감시하던 값 빼기: " << q.front() << endl;
            pq.pop();
            q.pop();
            cnt++;
            break;
        }
        else if (pq.top() == q.front()) {
            cout << "q에서 빼내기: " << q.front() << endl;
            pq.pop();
            q.pop();

            cnt++;

            if (current_location == 0) {
                current_location = q.size() - 1;
            }
            else {
                current_location--;
            }
        }
        else {
            cout << "뒤로 이동: " << q.front() << endl;
            temp = q.front();
            q.pop();
            q.push(temp);

            if (current_location == 0) {
                current_location = q.size() - 1;
            }
            else {
                current_location--;
            }
        }
    }
    answer = cnt;
    
    cout << answer;

    return answer;
}

int main() {

    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;

    solution(priorities, location);

    return 0;
}