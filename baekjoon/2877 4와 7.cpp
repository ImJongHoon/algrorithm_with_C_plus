#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	//4 7  44 47 74 77 444 447 474 477 744 747 774 777
	//1 2   3  4  5  6  7
	//0 1  00 01 10 11 000
	int num;
	cin >> num;
	
	int temp;
	int count= 0;
	//몇자리의 수인가?
	for (int i = 1; num > 0; num = num - pow(2, i++)) {
		temp = num;
		count++;
	}
	
	vector<int> arr(count, 0);
	//n자리수의 temp를 10
	//arr에는 뒷자리부터 저장됨
	temp = temp - 1;

	for (int i = 0; temp != 0; i++) {
		arr[i] = temp % 2;
		temp = temp / 2;
	}

	for (int i = count - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			cout << 4;
		}
		else if (arr[i] == 1) {
			cout << 7;
		}
		
	}

	return 0;
}