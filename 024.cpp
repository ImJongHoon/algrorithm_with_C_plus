#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int num = 0;
    int minus = 0;
    int result = 0;//참거짓

    scanf("%d", &num);

    vector<int> arr(num);
    vector<int> difference(num);

    difference[0] = 1;

    for(int i =0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < num-1; i++){
        if(arr[i] > arr[i+1]){
            minus = arr[i] - arr[i+1];
            //차에 저장된 배열 1 넣어줌
            difference[minus] = 1;
        }
        else{
            minus = arr[i+1] - arr[i];
            difference[minus] = 1;
        }
    }

    for (int i = 0; i<num; i++){
        if(1 != difference[i]){
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}