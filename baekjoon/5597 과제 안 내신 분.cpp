#include <iostream>

using namespace std;

int numArr[30] = {0};

int main(){

    int tempStd;
    int whiteSpace=0;

    for(int i=0; i<28; i++){
        cin >> tempStd;
        numArr[tempStd-1] = 1;
    }

    for(int i=0; i<30; i++){

        if(numArr[i] == 0){
            cout << i+1;
            if(whiteSpace==0){
                cout << "\n";
                whiteSpace = 1;
            }
        }
    }

    return 0;
}
