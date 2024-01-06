#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num, maxWeight;
    int weight, value;
    int maxValue = 0;

    cin >> num >> maxWeight;

    vector<int> knapsack(maxWeight+1, 0);

    for(int i=0; i<num;i++){
        cin >> weight >> value;
        
        for(int y=maxWeight; y>=weight; y--){
            knapsack[y] = max(knapsack[y], knapsack[y-weight] + value);
        }
    }

    maxValue = knapsack[maxWeight];
    
    cout << maxValue;

    return 0;
}