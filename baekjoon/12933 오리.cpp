#include <iostream>

using namespace std;

//오리의 최소 갯수를 구하라 == 가장 오리가 효율적으로 울었다.
//'q', 'u', 'a', 'c', 'k' 순
int quack[5] = { 0,};
char quack_str[5] = { 'q', 'u', 'a', 'c', 'k' };

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	char input[2501];
	int count = 0;
	int max_count = 0;
	
	cin >> input;
	
	//-1 출력 여부 결정
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == 'q') {
			quack[0] = quack[0] + 1;
		}
		else if (input[i] == 'u') {
			quack[1] = quack[1] + 1;
		}
		else if (input[i] == 'a') {
			quack[2] = quack[2] + 1;
		}
		else if (input[i] == 'c') {
			quack[3] = quack[3] + 1;
		}
		else if (input[i] == 'k') {
			quack[4] = quack[4] + 1;
		}
		else { // 아예 다른 소리가 오면
			cout << -1;
			return 0;
		}

		//순서가 어긋나거나
		if (quack[4] > quack[3] || quack[3] > quack[2] || quack[2] > quack[1] || quack[1] > quack[0]) {
			cout << -1;
			return 0;
		}
	}
	//끝까지 왔는데 갯수가 다 같지 않으면
	if (quack[4] != quack[3] || quack[3] != quack[2] || quack[2] != quack[1] || quack[1] != quack[0]) {
		cout << -1;
		return 0;
	}
	//아예 아무것도 없을 때도 예외처리
	if (input[0] != 'q') {
		cout << -1;
		return 0;
	}

	count = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		//q가 읽히면 거기서부터 검사하기 시작
		if (input[i] == 'q') {
			count++;
		}
		if (input[i] == 'k') {
			count--;
		}
		if (count > max_count) {//최대 넘으면 최대값 갱신
			max_count = count;
		}
	}

	cout << max_count;

	return 0;
}