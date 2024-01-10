#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;

    int num;

    cin >> num;

    int temp;

    //그냥 넣을 첫번째.
    cin >> temp;
    maxHeap.push(temp);
    cout << maxHeap.top() << "\n";

    for (int i = 1; i < num; i++) {
        cin >> temp;

        //일단 단순히 넣기
        if (i % 2 == 0) {
            maxHeap.push(temp);
        }
        else {
            minHeap.push(-temp);
        }

        
        int swapTemp;
        //비교. 평균 이하의 최대가 평균 이상의 최소보다 큰 경우
        if (maxHeap.top() > -minHeap.top()) {
            swapTemp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(-minHeap.top());
            minHeap.pop();
            minHeap.push(-swapTemp);
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}
