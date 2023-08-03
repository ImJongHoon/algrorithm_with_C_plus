#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string num1;
	string num2;
	for (int i = 0; i < n; i++) {
		int result[81] = { 0 };
		cin >> num1;
		cin >> num2;
		//덧셈
		int index1 = num1.length() - 1;
		int index2 = num2.length() - 1;
		int save = 0;
		for (int j = 0; j < 81; j++) {
			if (index1 - j < 0 && index2 - j < 0) {//둘 다 작으면
				result[80 - j] = save;//기본적으로는 0 들어있음 올림되면1
				save = 0;//한번 1로 올림 해주면 그다음에는 초기화
			}
			else if (index1 - j < 0) {//더 이상 저장된 숫자가 없는 경우
				if (save + (num2[index2 - j] - '0') == 2) {
					save = 1;
					result[80 - j] = 0;
				}
				else if (save + (num2[index2 - j] - '0') == 1) {
					save = 0;
					result[80 - j] = 1;
				}
				else {
					save = 0;
					result[80 - j] = 0;
				}
			}
			else if (index2 - j < 0) {
				if (save + (num1[index1 - j] - '0') == 2) {
					save = 1;
					result[80 - j] = 0;
				}
				else if (save + (num1[index1 - j] - '0') == 1) {
					save = 0;
					result[80 - j] = 1;
				}
				else {
					save = 0;
					result[80 - j] = 0;
				}
			}
			else {//평범한 덧셈
				if (save + (num1[index1 - j] - '0') + (num2[index2 - j] - '0') == 3) {
					save = 1;
					result[80 - j] = 1;
				}
				else if (save + (num1[index1 - j] - '0') + (num2[index2 - j] - '0') == 2) {
					save = 1;
					result[80 - j] = 0;
				}
				else if (save + (num1[index1 - j] - '0') + (num2[index2 - j] - '0') == 1) {
					save = 0;
					result[80 - j] = 1;
				}
				else {
					save = 0;
					result[80 - j] = 0;
				}
			}
		}

		//출력할 때 81자리인지 확인
		bool isFirst = false;
		if (result[0] == 1) {
			for (int j = 0; j < 81; j++) {
				cout << result[j];
			}
		}
		else if (result[0] == 0) {
			for (int j = 1; j < 81; j++) {
				if (result[j] == 1 && isFirst == false) {
					isFirst = true;
				}
				if (isFirst == true) {
					cout << result[j];
				}
			}
			//다 돌았는데 0이면
			if(isFirst == false) {
				cout << 0;
			}
		}
		
		cout << endl;
	}

	return 0;
}