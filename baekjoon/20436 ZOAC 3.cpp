#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct info {
	int ny;
	int nx;
};

//탐색을 쓰면 어차피 키보드 위치를 전부 받아야 함
info findInfo(char letter) {
	info result_info;

	switch (letter) {
	case 'q':
		result_info.ny = 0;
		result_info.nx = 0;
		break;
	case 'w':
		result_info.ny = 0;
		result_info.nx = 1;
		break;
	case 'e':
		result_info.ny = 0;
		result_info.nx = 2;
		break;
	case 'r':
		result_info.ny = 0;
		result_info.nx = 3;
		break;
	case 't':
		result_info.ny = 0;
		result_info.nx = 4;
		break;
	case 'y':
		result_info.ny = 0;
		result_info.nx = 5;
		break;
	case 'u':
		result_info.ny = 0;
		result_info.nx = 6;
		break;
	case 'i':
		result_info.ny = 0;
		result_info.nx = 7;
		break;
	case 'o':
		result_info.ny = 0;
		result_info.nx = 8;
		break;
	case 'p':
		result_info.ny = 0;
		result_info.nx = 9;
		break;

	case 'a':
		result_info.ny = 1;
		result_info.nx = 0;
		break;
	case 's':
		result_info.ny = 1;
		result_info.nx = 1;
		break;
	case 'd':
		result_info.ny = 1;
		result_info.nx = 2;
		break;
	case 'f':
		result_info.ny = 1;
		result_info.nx = 3;
		break;
	case 'g':
		result_info.ny = 1;
		result_info.nx = 4;
		break;
	case 'h':
		result_info.ny = 1;
		result_info.nx = 5;
		break;
	case 'j':
		result_info.ny = 1;
		result_info.nx = 6;
		break;
	case 'k':
		result_info.ny = 1;
		result_info.nx = 7;
		break;
	case 'l':
		result_info.ny = 1;
		result_info.nx = 8;
		break;

	case 'z':
		result_info.ny = 2;
		result_info.nx = 0;
		break;
	case 'x':
		result_info.ny = 2;
		result_info.nx = 1;
		break;
	case 'c':
		result_info.ny = 2;
		result_info.nx = 2;
		break;
	case 'v':
		result_info.ny = 2;
		result_info.nx = 3;
		break;
	case 'b':
		result_info.ny = 2;
		result_info.nx = 4;
		break;
	case 'n':
		result_info.ny = 2;
		result_info.nx = 5;
		break;
	case 'm':
		result_info.ny = 2;
		result_info.nx = 6;
		break;
	}

	return result_info;
}

int main() {
	//왼쪽 손가락은 자음만, 오른쪽 손가락은 모음만 칠 수 있다는 것도 중요할듯
	//누를 때 시간 1, 한칸 이동할때 시간1
	char sl;
	char sr;
	string input;
	info left_info;//왼쪽(자음) 손가락 위치
	info right_info;//오른쪽(모음) 손가락 위치
	info aim_info;//목표 글자의 위치
	int count=0;

	cin >> sl;
	cin >> sr;
	cin >> input;

	left_info = findInfo(sl);
	right_info = findInfo(sr);


	//1. 단어의 글자 선택, 2.해당 글자가 자음영역인지 모음영역인지 파악
	for (int i = 0; input[i] != '\0'; i++) {
		//목표 글자의 위치
		aim_info = findInfo(input[i]);
		if (aim_info.ny < 2) {
			if (aim_info.nx < 5) {//왼손가락
				count = count + abs(left_info.ny - aim_info.ny);
				count = count + abs(left_info.nx - aim_info.nx);
				left_info.ny = aim_info.ny;
				left_info.nx = aim_info.nx;
			}
			else {//오른손가락
				count = count + abs(right_info.ny - aim_info.ny);
				count = count + abs(right_info.nx - aim_info.nx);
				right_info.ny = aim_info.ny;
				right_info.nx = aim_info.nx;
			}
		}
		else if (aim_info.ny == 2) {
			if (aim_info.nx < 4) {//왼손가락
				count = count + abs(left_info.ny - aim_info.ny);
				count = count + abs(left_info.nx - aim_info.nx);
				left_info.ny = aim_info.ny;
				left_info.nx = aim_info.nx;
			}
			else {//오른손가락
				count = count + abs(right_info.ny - aim_info.ny);
				count = count + abs(right_info.nx - aim_info.nx);
				right_info.ny = aim_info.ny;
				right_info.nx = aim_info.nx;
			}
		}
		//누르는 시간
		count++;
	}

	cout << count;

	return 0;
}