#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int num;
    cin >> num;
    int i, j = 0;

    vector<int> arr(num);

    for(int i=0; i < num; i++){
        cin>>arr[i];
    }

    for(i=1; i<num; i++){
        int temp = arr[i];
        for(j=i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    for(int i=0; i<num; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}