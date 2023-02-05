#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){

    int size = 0;
    int* arr;
    int min, max;
    int result;
    
    cin>>size;

    arr = new int[size];

//나이 입력
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

//정렬 라이브러리 코드 써보기
    sort(arr, arr+size);

    result = arr[size-1] - arr[0];

    cout<<result;

    return 0;
}