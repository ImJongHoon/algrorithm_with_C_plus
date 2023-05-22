#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int num;

    scanf("%d", &num);

    vector<int> player(num);
    vector<int> grade(num, 1); //성적 전부 1로 초기화

    for(int i =0; i<num; i++){
        scanf("%d", &player[i]);
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<i; j++){
            if(player[i] <= player[j]){//반복문 돌면서 자신의 앞에 있는 놈들과 크기 비교
                grade[i]++; //숫자 증가
            }
        }
    }

    for(int i = 0; i<num; i++){
        printf("%d ", grade[i]);
    }

    return 0;
}