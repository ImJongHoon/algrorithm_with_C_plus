#include <iostream>
#include <stdio.h>
#include <cmath>

// 더 간단히 만들 수 있음. 리팩토링하기

using namespace std;

int main(int argc, char** argv){

    char* str;
    int numArr[10];
    int arrIndex = 0;
    int count = 0;

//a를 정수형으로 해줘야 아스키코드로 받음
    char a;
    int asci;
    int i = 0;
    int sum =0;

    str = new char[51];

    scanf("%s", str);

    //일단 a에 첫번째 배열 넣어주고
    a = str[i];
    asci = a -'0';

    //추출문
    while(a != '\0'){
        
        //아스키 코드로 구분. 일의자리에서부터 배열에 들어감.
        if(asci>=0 && asci<=9){
            numArr[arrIndex] = asci;
            arrIndex++;
        }

        i++;
        a = str[i];
        asci = a -'0';
    }

    //자연수 만들기.
    for(int k=0; k<arrIndex; k++){
        sum = sum + (numArr[k] * pow(10, arrIndex-k-1));
    }

    for(int i =0; i<sum; i++){
        if(sum % (i+1) == 0){
            count++;
        }
    }

    printf("%d\n", sum);
    printf("%d", count);
    
    delete str;

    return 0;
}