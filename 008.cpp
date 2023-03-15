#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    int count = 0;
    char brackets[31];

    scanf("%s", brackets);

    for(int i = 0; brackets[i] != '\0'; i++){
        if(brackets[i] == '('){
            count++;
        }
        else if(brackets[i] == ')'){
            count--;
        }
        if(count < 0){
            break;
        }
    }
    if(count == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}