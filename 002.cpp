#include <iostream>

int main(int argc, char** argv){
    int a;
    int b;
    int count, sum = 0;

    std::cin>>a>>b;

    count = b - a;
    
    for(int i =0; i<count; i++){
        sum = sum + a + i;
        std::cout<<a+i<< " +";
    }

    sum = sum + b;

    std::cout<<b<<" = "<< sum;

    return 0;
}