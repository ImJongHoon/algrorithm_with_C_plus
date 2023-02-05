#include <iostream>

int main(int argc, char** argv){
    
    int n, m, i = 1 , sum = 0;

    std::cin >>n>>m;

    while(i * m <= n){
        sum = sum + (m * i);
        i++;
    }

    std::cout<<sum;

    return 0;
}