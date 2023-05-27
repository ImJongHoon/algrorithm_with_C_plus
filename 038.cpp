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

// input outpu이 반대인 경우
// int num;
//     int i, j;
//     int temp;
//     int count =0;

//     scanf("%d", &num);

//     vector<int> arr(num);
//     vector<int> result(num);
	
//     for(i=0; i<num; i++){
//         scanf("%d", &arr[i]);
//     }

//     for(i=0; i<num; i++){
//         count = 0;
//         temp = arr[i];
//         printf("%d", i);

//         //index i가 현재 비교 대상, 따라서 j = i-1 즉, i보다 한 단계 전부터 시작함.
//         for(j=i-1; j>=0; j--){

//             if(arr[j] > temp){
//                 arr[j+1] = arr[j];
//                 count++;
//             }
//             else{//arr[j] 가 temp보다 작은 순간 탈출
//                 break;
//             }
//         }
//         arr[j+1] = temp;

//         //index는 해당 숫자 -1 값이다.
//         result[temp-1] = count;
//     }

//     for(i=0; i<num; i++){
//         printf("%d", result[i]);
//     }