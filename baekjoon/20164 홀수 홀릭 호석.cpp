#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int odd_min = 987654321;
int odd_max = 0;

//재귀에서 하나의 스탭이 무엇인지 파악하기. 여기서는 자르고 더하는 것까지가 하나의 스탭이다.
//재귀에서 스택 사이에 정보를 교환하기 위해서는, 인자로 교환할 정보를 넣는다!
//재귀로 할 수 있는것과 없는것을 구별해야 함! 여기서는 재귀 내에서 최대 최소를 구하는 건 불가능!
//최대 최소는 재귀 밖에서 구하고, 재귀로는 모든 경우의 수의 odd_cnt를 출력하도록 짜면 됨.
void calcOdd(string number, int odd_cnt) {
	for (int i = 0; i < number.length(); i++) {
		if (int(number[i] - '0') % 2 == 1) {
			odd_cnt++;
		}
	}

	if (number.length() == 1) {//탈출조건
		odd_min = min(odd_min, odd_cnt);
		odd_max = max(odd_max, odd_cnt);
		return;
	}
	else if (number.length() == 2) {
		calcOdd(to_string((number[0] - '0') + (number[1] - '0')), odd_cnt);
	}
	else {//3이상
		//자르는 모든 경우의 수. 
		//substr 함수는 인자 A부터 인자B의 길이만큼 출력한다.
		for (int i = 1; i < number.size() - 1; i++) {//처음부터 몇번째까지 자를 것인가?(몇개)
			for (int j = 1; i + j < number.size(); j++) {
				//바로바로 출력해보기
				int sum;
				sum = stoi(number.substr(0, i)) + stoi(number.substr(i, j)) + stoi(number.substr(i + j));
				calcOdd(to_string(sum), odd_cnt);
			}
		}
	}
}

int main() {
	//최대 10자리. 즉 자를 수 있는 위치는 최대 9자리.
	string num;

	cin >> num;

	calcOdd(num, 0);

	cout << odd_min << " ";
	cout << odd_max;

	return 0;
}