#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int a, sum =0;

    cin>>a;

    cout<<1;
    sum = sum +1;

    for(int i = 2; i<a; i++){
        if(a%i == 0){
            cout<<" + "<<i;
            sum = sum + i;
        }
    }

    cout<< " = " << sum;

    return 0;
}