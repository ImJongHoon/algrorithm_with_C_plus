#include <iostream>

using namespace std;

int main(int argc, char** argv){
    freopen("input.txt", "rt", stdin);

    char num[15];
    int year, age;

    cin>>num;

    if(num[7] == '1'){
        year = 1900 + (num[0] - '0')*10 + (num[1] - '0');
        age = 2019 - year + 1;
    }
    else if(num[7] == '2'){
        year = 1900 + (num[0] - '0')*10 + (num[1] - '0');
        age = 2019 - year + 1;
    }
    else if(num[7] == '3'){
        year = 2000 + (num[0] - '0')*10 + (num[1] - '0');
        age = 2019 - year + 1;
    }
    else if(num[7] == '4'){
        year = 2000 + (num[0] - '0')*10 + (num[1] - '0');
        age = 2019 - year + 1;
    }

    cout << age;

    return 0;
}