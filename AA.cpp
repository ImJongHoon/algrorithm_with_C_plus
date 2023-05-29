#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int main() {
	int num=0;
    int i;
    int count;
    int temp;

    scanf("%d", &num);

    vector<int> inversion_arr(num);
    vector<int> result_arr(num);
	
    for(i=0; i<num; i++){
        scanf("%d", &inversion_arr[i]);
    }

    for(i=0; i<num; i++){
        temp = inversion_arr[i];
        for(int j=0; j<num; j++){
            if(result_arr[j] == 0){
                temp--;
                if(temp == -1){
                    result_arr[j] = i+1;//여기에 저장되는 게 곧 숫자이다.
                    break;
                }
            }
        }
    }


    for(i=0; i<num; i++){
        printf("%d ", result_arr[i]);
    }

	return 0;
}
