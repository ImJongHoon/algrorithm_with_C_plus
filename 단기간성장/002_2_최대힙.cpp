#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int> pq;  
    
    int num;

    cin >> num;

    int temp;

    for(int i=0; i<num; i++){
        cin >> temp;
        if(temp == 0){
            if(pq.size() == 0){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        
        pq.push(temp);
    }

    return 0;
}
