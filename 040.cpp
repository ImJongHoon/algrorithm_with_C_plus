#include <iostream>
#include <vector>
#include <algorithm>
//two pointer 알고리즘
//투포인터 알고리즘은 각각 정렬이 되어 있어야 한다.
using namespace std;
int main() {
	int numA, numB;

	cin >> numA;
	vector<int>arrA(numA);
	for(int i=0; i<numA; i++){
		cin >> arrA[i];
	}
	//이터레이터
	sort(arrA.begin(), arrA.end());

	cin >> numB;
	vector<int>arrB(numB);
	for(int i=0; i<numB; i++){
		cin >> arrB[i];
	}
	sort(arrB.begin(), arrB.end());

	int pointerA=0;
	int pointerB=0;
	int pointerC=0;
	vector<int> arrC(min(numA, numB));

	while(pointerA < numA && pointerB < numB){
		if (arrA[pointerA] > arrB[pointerB]){
			pointerB++;
		}
		else if(arrA[pointerA] < arrB[pointerB]){
			pointerA++;
		}
		else if(arrA[pointerA] == arrB[pointerB]){
			arrC[pointerC] = arrA[pointerA];
			pointerC++;
			pointerA++;
			pointerB++;
		}
	}

	for(int i=0; arrC[i] != 0; i++){
		cout << arrC[i] <<" ";
	}

	return 0;
}
