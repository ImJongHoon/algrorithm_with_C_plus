#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    
    //소수 배열 생성 index = 해당 숫자
    int primeNum[1001] = {0};
    //0과 숫자 1은 소수 아님
    primeNum[0] = -1;
    primeNum[1] = -1;


    //소수에 전부 0, 나머지 -1
    for(int i = 2; i<1001; i++){
        if(primeNum[i] == 0){
            for(int j = 2; j*i < 1001; j++){
                primeNum[j*i] = -1;
            }
        }
    }
    
    int num;

    scanf("%d", &num);

    for(int i = 2; i<num+1; i++){//곱하는 수
        int temp = i; // 나눠줄 숫자 저장

        for(int j = 2; j <= i; j++){
            if(primeNum[j] != -1){//소수만
                while(temp % j == 0){//index가 숫자임. prime[j]는 횟수임
                    temp = temp / j;
                    primeNum[j]++;
                }
            }
        }
    }

    printf("%d! =", num);
    for(int i = 2; i<=num; i++){
        if(primeNum[i] != -1){
            printf(" %d", primeNum[i]);
        }
    }    
    return 0;
}