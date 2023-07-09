#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n1, n2;//배열 크기
	int p1 =0;
	int p2 =0;
	int p3 = 0;

	cin >> n1;
	vector<int> arr1(n1);
	for(int i=0; i<n1; i++){
		cin >> arr1[i];
	}

	cin >> n2;
	vector<int> arr2(n2);
	for (int j=0; j<n2; j++){
		cin >> arr2[j];
	}

	vector<int> arr3(n1+n2);
	//병합정렬에서는 포인터를 두고 포인터의 위치를 추론하는게 
	while(p1 < n1 && p2 < n2){
		if(arr1[p1] >= arr2[p2]){
			arr3[p3] = arr2[p2];
			p2++;
		}
		else{
			arr3[p3] = arr1[p1];
			p1++;
		}
		p3++;
	}
	
	while(p1<n1){
		arr3[p3] = arr1[p1];
		p3++;
		p1++;
	}
	while(p2<n2){
		arr3[p3] = arr2[p2];
		p3++;
		p2++;
	}
	for(int i=0; i<n1+n2; i++){
		cout << arr3[i] << " ";
	}

	return 0;
}
