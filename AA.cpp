#include <iostream>
#include <stdio.h>
#include<cmath>

using namespace std;

int digit_sum( int x ){
    int sum = 0 ;
    int temp;

    for(int i = 0; i < 7; i++){
        int div_num1 = x / pow(10, i);
        int div_num2 = x / pow(10, i+1);
        temp = div_num1 - (div_num2 * 10);

        sum = temp + sum;
    }

    return sum;
}

int main(int argc, char** argv){
    int n;
    int numArr[101] = {0};
    int calArr[101] = {0};
    int maxSum=0;
    int maxNum=0;

    scanf("%d", &n);

    for (int i = 0; i<n ; i++){
        scanf("%d", &numArr[i]);
        calArr[i] = digit_sum(numArr[i]);

        if(calArr[i] > maxSum) {
            maxSum = calArr[i];
            maxNum = numArr[i];
        }
        else if(calArr[i] == maxSum){
            if(numArr[i] > maxNum){
                maxNum = numArr[i];
            }
        }
    }

    printf("%d", maxNum);

    return 0;
}