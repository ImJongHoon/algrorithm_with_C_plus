//시작 2:38
//끝
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int playerNum;
	int height;
	cin >> playerNum;
	cin >> height;

	vector<char> resultPlayer(playerNum);
	for (int i = 0; i < playerNum; i++) {
		cin >> resultPlayer[i];
	}

	vector<vector<char>> ladder(height, vector<char>(playerNum - 1));
	int unknownY;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < playerNum - 1; x++) {
			cin >> ladder[y][x];
			if (ladder[y][x] == '?') {//? 위치 알아두고
				unknownY = y;
			}
		}
	}

	//위에서 ? 전까지 내려온 값, 아래에서 ?까지 올라온 값 구하기
	vector<char>beforePlayer(playerNum);
	int position;
	for (int x = 0; x < playerNum; x++) {
		position = x;//현재 위치한 막대
		for (int y = 0; y < unknownY; y++) {
			if (position - 1 < 0) {//out of range 예외처리
				if (ladder[y][position] == '-') {
					position++;
				}
			}
			else if (position >= playerNum - 1) {
				if (ladder[y][position - 1] == '-') {
					position--;
				}
			}
			else {
				if (ladder[y][position-1] == '-') {
					position--;
				}
				else if (ladder[y][position] == '-') {
					position++;
				}
			}
		}
		beforePlayer[position] = 'A' + x;
	}

	vector<char>afterPlayer(playerNum);
	for (int x = 0; x < playerNum; x++) {
		position = x;
		for (int y = height -1; y > unknownY; y--) {
			if (position - 1 < 0) {//out of range 예외처리
				if (ladder[y][position] == '-') {
					position++;
				}
			}
			else if (position >= playerNum - 1) {
				if (ladder[y][position - 1] == '-') {
					position--;
				}
			}
			else {
				if (ladder[y][position - 1] == '-') {
					position--;
				}
				else if (ladder[y][position] == '-') {
					position++;
				}
			}
		}
		afterPlayer[position] = resultPlayer[x];
	}
	
	/*
	for (int i = 0; i < playerNum; i++) {
		cout << beforePlayer[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < playerNum; i++) {
		cout << afterPlayer[i] << " ";
	}
	*/

	vector<int> isSame(playerNum, 0);
	for (int i = 0; i < playerNum; i++) {
		if (beforePlayer[i] == afterPlayer[i]) {
			isSame[i] = 1;
		}
	}
	for (int i = 0; i < playerNum-1; i++) {//한번 적게 돌기
		if (beforePlayer[i] == afterPlayer[i+1]) {//다음거랑 같으면
			isSame[i] = 2;
		}
	}
	for (int i = 1; i < playerNum; i++) {//한번 적게 돌기
		if (beforePlayer[i] == afterPlayer[i-1]) {//다음거랑 같으면
			isSame[i] = 1;
		}
	}
	
	//출력 결정하기
	for (int i = 0; i < playerNum - 1; i++) {
		if (isSame[i] == 0) {
			for (int j = 0; j < playerNum - 1; j++) {
				cout << 'x';
			}
			return 0;
		}
	}

	for (int i = 0; i < playerNum - 1; i++) {
		if (isSame[i] == 1) {
			cout << '*';
		}
		else if (isSame[i] == 2) {
			cout << '-';
		}
	}

	return 0;
}