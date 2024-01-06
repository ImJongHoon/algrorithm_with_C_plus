#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//string 형에서 + 연산은 O(1) 이 아니다.
//O(n+m) 이다. 문자열 길이가 n과 m일때.
//문자열 뒤에 문자를 하나 붙혀야 O(1)

//최적화하는 법 1. 그냥 출력해보기

string numArr[]={"000", "001", "010", "011", "100", "101", "110", "111"};
string firstNumArr[]={"", "1", "10", "11", "100", "101", "110", "111"};

int main(){
    string n;
    string result="";
    string index="";
    string tempStr="";
    int temp;

    cin >> n;

    //0인 경우에는 0출력
    //뒤에서부터 세자리씩 출력
    if(n=="0"){
        cout << "0";
    }
    else{
        index = n[0];
        cout << firstNumArr[stoi(index)];

        for(int i=1; i<n.length(); i++){//마지막은 0빼줘야하니까 앞에서 미리 계산
            index = n[i];
            cout << numArr[stoi(index)];
        }
        //0만 따로
        cout << result;
    }
    

    return 0;
}