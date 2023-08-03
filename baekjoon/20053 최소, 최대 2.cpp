#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    
    int testCaseNum = 0;
    int vectorSize=0;
    int max, min;
    int temp=0;

    cin >> testCaseNum;

    for(int i=0; i<testCaseNum; i++){
        cin >> vectorSize;
        max = -1000001;
        min = 1000001;

        for(int j=0; j<vectorSize; j++){
            cin >> temp;
            if(temp > max){
                max = temp;
            }
            if( temp < min ){
                min = temp;
            }
        }

        cout << min << " " << max <<endl;
    }

    return 0;
}