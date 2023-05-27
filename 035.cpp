#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv){
    int num;
    int temp;
    scanf("%d", &num);

    vector<int> numV(num);
    
    for(int i=0; i<num; i++){
        scanf("%d", &numV[i]);
    }

    for(int i = 0; i<num-1; i++){
        for(int j=0; j<num-1-i; j++){
            if(numV[j] > 0 && numV[j+1] < 0){
                temp = numV[j];
                numV[j] = numV[j+1];
                numV[j+1] = temp;
            }
        }
    }

    for(int i=0; i<num; i++){
        printf("%d ", numV[i]);
    }

    return 0;
}