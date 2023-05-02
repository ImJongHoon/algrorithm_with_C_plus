#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

//이 배열은 고정 수치로 해두는 편이 좋으니 배열을 사용. 받는 input 은 가변적인 편이 효율적이니 vector 사용.
int checkPrime[100001] = {0};

int reverse(int x){

    //첫번째 자리부터 0인 경우.
    int isFirstZero = 1;
    int inputNum = x;
    int count = 0; //자리 수 카운팅
    int result = 0;
    int numArr[7]= {0};

    while(inputNum != 0){
        //0이 아닌게 오면 isFirstZero에 0 대입
        if(inputNum % 10 != 0){
            isFirstZero = 0;
        }

        //0이 나왔으면 되돌아가
        if(isFirstZero == 1){
            inputNum = inputNum / 10;
        }
        else {
            numArr[count] = inputNum % 10;
            count++;
            inputNum = inputNum / 10;
        }
    }



    for(int i = 0; i<count; i++){
        result = result + (numArr[i] * pow(10, count-1-i));
    }

    return result;
}

bool isPrime(int x){
    if(checkPrime[x] == 1){
        return false;
    }
    else if(checkPrime[x] == 0) {
        return true;
    }
}

int main(int argc, char** argv){

    //가변 크기로 받는게 좋을 것 같은 input 숫자는 가변으로.
    int num;

    scanf("%d", &num);

    vector<int>inputV(num);
    
    for(int i = 0; i < num; i++){
        scanf("%d", &inputV[i]);
    }

    //역으로 바꾼 값 넣어주기.
    for(int i = 0; i<num; i++){
        inputV[i] = reverse(inputV[i]);
    }

    //배열 소수 골라주기 0이 소수, 1이 소수 아님. 
    for(int i= 2; i<100001; i++){
        if(checkPrime[i] == 0){
            for(int j=2*i; j<100001; j = j+i){
                checkPrime[j] = 1;
            }
        }
    }

    //소수인 값만 출력하기
    for(int i = 0; i<num; i++){
        if(isPrime(inputV[i]) == true){
            printf("%d ", inputV[i]);
        }
    }
    
    return 0;
}