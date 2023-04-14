#include <stdio.h>

//1의 자릿수를 넘으면 1을 9번 더해서 9, 10의자리 숫자를 넘는건 90개에 2개씩 있으니 180 ... 이렇게 자리에 따라 계산한다.
int main(int argc, char** argv){

    int num = 0;
    int count = 0;
    int temp = 0;
    int sum = 0;

    //얼마를 곱해서 더해주는가
    int multiplication = 1;

    scanf("%d", &num);

    temp = num;

    //자릿수 구하기
    while(temp =! 0){
        temp = temp/10;
        count++;
        printf("1");
    }

    //계산을 무시하는건 한자리 낮은 숫자까지이다.
    for(int i = 0; i<count -1; i++){
        
        sum = sum + (9*multiplication * (i+1));
        multiplication = multiplication * 10;
    }

    //매크로로 구한 값
    multiplication = multiplication * 10 - 1;

    num = num - multiplication;
    sum = sum + (num * count);

    printf("%d", sum);

    return 0;
}