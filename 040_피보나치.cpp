#include <iostream>

using namespace std;

int fibonacci(int n){
    int num;
    //탈출문
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    num = fibonacci(n-1) + fibonacci(n-2);

    return num;
}

int main(){
    int n;

    cin >> n;
    cout << fibonacci(n);

    return 0;
}
/*
결국 구조가 머리에 그려져야 함
fib(5)
f(4)  +  f(3)
f(3)+f(2)  +  f(2)+f(1)
...

스택으로 구조를 그리는 것도 괜찮음
먼저오는 함수가 스택의 바닥부터 쌓이고 맨 마지막에
조건문에서 가장 최근부터 pop되기 시작.
*/