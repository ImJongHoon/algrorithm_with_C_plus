#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int N, K;
    int maxNum = 0; // 영하가 최대일 수 있기 때문에 첫번째는 값이 그냥 들어가야 함.
    int temp = 0;
    scanf("%d", &N);
    scanf("%d", &K);

    vector<int> arr(N);

//전체 횟수만큼 입력
    for(int i =0 ; i < N ; i++){
        scanf("%d", &arr[i]); 
    }

//Maxnum 초기화
    for(int i = 0; i<K ; i++){
        maxNum = maxNum + arr[i];
    }
    temp = maxNum;

    for(int i = 1; i< N-K+1; i++){
        //이전 숫자 빼주기
        temp = temp - arr[i-1];

        //이번 범위의 끝 숫자 더해주기(현재 번째 + k -1까지)
        temp = temp + arr[i + K - 1];

        if(temp > maxNum){
            maxNum = temp;
        }
    }

    printf("%d", maxNum);

    return 0;
}