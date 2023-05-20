#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    //배열2개만들고
    //input 두번
    //비교 반복문
    //제일 마지막에 이긴 승자 누군지 저장해두기 (0이면 아예 비김, 1이면 A가 승자, 2면 B가 승자)
    //반복문 내부에서 크기 비교와 승점 저장

    int arrA[10];
    int arrB[10];
    int whoWin = 0;
    int A_point = 0;
    int B_point = 0;
    
    for(int i=0; i < 10;i++){
        scanf("%d", &arrA[i]);
    }
    for(int i=0; i < 10;i++){
        scanf("%d", &arrB[i]);
    }

    for(int i=0; i<10 ; i++){
        if(arrA[i] > arrB[i]){
            A_point = A_point + 3;
            whoWin = 1;
        }
        else if(arrA[i] < arrB[i]){
            B_point = B_point + 3;
            whoWin = 2;
        }
        else {
            A_point++;
            B_point++;
        }
    }

    printf("%d %d\n", A_point, B_point);

    if(whoWin == 0){
        printf("D");
    }
    else if(A_point > B_point){
        printf("A");
    }
    else if(A_point > B_point){
        printf("A");
    }
    else if(A_point == B_point){
        if(whoWin == 1){
            printf("A");
        }
        else if(whoWin == 2){
            printf("B");
        }
    }

    return 0;
}