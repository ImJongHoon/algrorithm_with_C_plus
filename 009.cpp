#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    int numArr[50001] = {0};
    int inputN;

    scanf("%d", &inputN);

    for(int i = 1; i<inputN+1; i++){
        for(int j=i; j<inputN+1; j = j+i){
            numArr[j] = numArr[j] + 1;
        }
    }

    for(int i = 1; i < inputN+1 ; i++){
        printf("%d ", numArr[i]);
    }

    return 0;
}