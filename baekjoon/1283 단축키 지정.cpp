#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int checkFirstLetter(vector<vector<string>>& options, int option_index , vector<bool>&alphabetArr) {
	int word_index = -1;
	int arrIndex;
	for (int i = 0; options[option_index][i] != "\0"; i++) {
		//대소문자? A = 65 a=97
		if (options[option_index][i][0] > 96) {//소문자면
			arrIndex = options[option_index][i][0] - 97;
		}
		else {
			arrIndex = options[option_index][i][0] - 65;
		}
		if (alphabetArr[arrIndex] == false) {
			alphabetArr[arrIndex] = true;
			word_index = i;
			break;
		}
	}

	return word_index;
}

int main() {
	int num;//옵션 갯수
	cin >> num;

	vector<vector<string>> options(num, vector<string>(6, "\0"));//하나의 옵션당 5개 단어.

	//옵션의 단어 구분해서 입력받기 - 띄어쓰기로 저장되어있음.
	//getline(cin, string, ',') 이런 식으로 사용시 특정 문자를 기준으로 구분 가능
	string option;//임시저장
	char seperator = ' ';//구분자
	int index;
	cin.ignore(); //버퍼 비워주기 암기!!!!!
	for (int i = 0; i < num; i++) {
		getline(cin, option, '\n');

		istringstream iss(option);
		index = 0;
		while (getline(iss, options[i][index], seperator)) {
			//cout << options[i][index]<<endl;
			index++;
			if (index >= 5) {
				break;
			}
		}
		//cout << endl;
	}

	vector<bool>alphabetArr(26, false);//26개임

	int word_index;
	int letter_index;
	int arrIndex;
	for (int i = 0; i < num; i++) {
		int j = 0;
		word_index = -1;
		letter_index = 0; // 단어 위치만 찾으면 자동으로 첫번째임을 증명

		//단어 첫글자 확인
		word_index = checkFirstLetter(options, i, alphabetArr);

		//글자 단위 일일이 확인
		if (word_index == -1) {
			while (options[i][j] != "\0") {
				//글자 하나씩 검사
				for (int k = 0; k < options[i][j].length(); k++) {
					//대소문자? A = 65 a=97
					if (options[i][j][k] > 96) {//소문자면
						arrIndex = options[i][j][k] - 97;
					}
					else {
						arrIndex = options[i][j][k] - 65;
					}

					//cout << "arrIndex: " << arrIndex << endl;

					//이미 있는 단축키인지 확인
					if (alphabetArr[arrIndex] == false) {
						alphabetArr[arrIndex] = true;
						word_index = j;
						letter_index = k;
						break;
					}
				}
				
				if (word_index != -1) {//찾아서 탈출한거면 단어 단위 검사도 탈출
					break;
				}
				j++;
			}
		}

		//단축키 만드는데 성공했을 경우 출력
		if (word_index != -1) {
			int l = 0;
			for (int x = 0; options[i][x] != "\0"; x++) {
				for (int y = 0; y < options[i][x].length(); y++) {
					if (x == word_index && y == letter_index) {
						cout << "[" << options[i][x][y] << "]";
					}
					else {
						cout << options[i][x][y];
					}
				}
				cout << " ";
			}
			cout << endl;
		}
		else {//아니면 그냥 출력
			int l = 0;
			while (options[i][l] != "\0") {
				cout << options[i][l] << " ";
				l++;
			}
			cout << endl;
		}
	}

	//'단어'의 첫 글자 확인.
	// 단어의 첫글자가 모두 예약이 되어있다면, 그냥 옵션 이름에서 왼쪽부터 보기
	// 자리 없으면 그냥 둠. 그리고 대소문자를 구분하지 않음.


	return 0;
}

//암기
/*
1. cin.ignore로 지운다
2. getline(cin, 변수, seperator)으로 받기
*/