#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    
    //0~25는 대문자 알파벳, 26~51은 소문자 알파벳
    int arr[52] = {0};

    char firstWord[101];
    char secondWord[101];

    int index = 0;

    //검사해보면 A 65시작, a 97시작
    // char a = 'a';

    // printf("%d", a);

    scanf("%s", &firstWord);
    scanf("%s", &secondWord);

    //배열에 1 더해 주고
    for(int i = 0; firstWord[i] != '\0'; i++){
        if(firstWord[i] >= 65 && firstWord[i] <= 90){
            //배열 0부터 시작해서 값 증가
            index = firstWord[i] - 65;
            arr[index] = arr[index] + 1;
        }
        else if(firstWord[i] >= 97 && firstWord[i] <= 122){
            //배열 27번째(index26)부터 시작해서 값 증가
            index = firstWord[i] - 71;
            arr[index] = arr[index] + 1;
        }
    }

    //배열에 1 빼 주고
    for(int i = 0; secondWord[i] != '\0'; i++){
        if(secondWord[i] >= 65 && secondWord[i] <= 90){
            //배열 0부터 시작해서 값 감소
            index = secondWord[i] - 65;
            arr[index] = arr[index] - 1;
        }
        else if(secondWord[i] >= 97 && secondWord[i] <= 122){
            //배열 27번째(index26)부터 시작해서 값 감소
            index = secondWord[i] - 71;
            arr[index] = arr[index] - 1;
        }
    }

    //모든 배열이 0인지 확인하고
    for(int i =0; i<52; i++){
        if(arr[i] != 0){
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}