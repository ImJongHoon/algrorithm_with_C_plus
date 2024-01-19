#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;

    int calcDay;
    for (int i = 0; i < progresses.size(); i++) {
        calcDay = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) {
            calcDay++;
        }

        days.push_back(calcDay);
    }


    queue<int> leftProgress;
    int cnt;

    for (auto day : days) {
        if (leftProgress.empty()) {
            leftProgress.push(day);
        }
        else {
            //3 , 2 , 1 순서면 top에 3이, day에 2가 들어가게 됨
            if (leftProgress.front() >= day) {//다음 숫자가 작거나 같으면 계속 queue에 넣어주는 것.
                leftProgress.push(day);
                
            }
            else {
                answer.push_back(leftProgress.size());
                while (!leftProgress.empty()) {
                    leftProgress.pop();
                }
                leftProgress.push(day);
            }
        }
    }
    
    //마지막에 다 처리되는거 한번더
    if (!leftProgress.empty()) {
        answer.push_back(leftProgress.size());
    }

    return answer;
}

int main() {


    return 0;
}