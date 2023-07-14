#include <iostream>
#include <vector>

//연속된 수라는 개념을 가지고 2가지 방법론을 떠올릴 수 있다.
//1. 1, 2, 3 같이 기본적인 연속 수열에 각각 n을 더하는 방법
//2. 1 2 3 4 ... 의 연속된 숫자 사이의 부분 배열 (투포인트 알고리즘으로)
using namespace std;
int main() {
	int num;
	
	cin >> num;

	vector<int> numArr(num/2 + 1);

	for(int i=0; i<numArr.size(); i++){
		numArr[i] = i+1;
	}

	//투포인터 알고리즘
	int ptr1 = 0;
	int ptr2 = 0;
	int sum=0;
	int count=0;

	while(ptr2 < numArr.size()){//ptr2가 인덱스 밖으로 나가면
		sum=0;
		//반복을 
		for(int i=ptr1; i<ptr2+1; i++){//포인터 하고 있는 애를 더하기
			sum = sum + numArr[i];
		}
		if(sum < num){
			ptr2++;
		}
		else if(sum > num){
			ptr1++;
		}
		else if(sum == num){
			cout << numArr[ptr1] << " ";//미리 하나 출력
			for(int i=ptr1+1; i<ptr2+1; i++){//포인터 하고 있는 애를 더하기
				cout << "+ " << numArr[i] <<" ";
			}
			cout << "= " << num << endl;
			count++;
			ptr1++;
		}
	}

	cout << count;
	return 0;
}
