//시작 12시 45분
//종료 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int num;

	cin >> num;

	vector<string> word(num);

	for (int i = 0; i < num; i++) {
		cin >> word[i];
	}

	//알파벳 등장 검사 a~z
	int alphabet_num = ('z' - 'a') + 1;
	vector<int> checker(alphabet_num, 0);

	char temp_alphabet;//이전 알파벳 저장
	int count = 0;//그룹단어 갯수
	for (int i = 0; i < num; i++) {
		temp_alphabet = word[i][0];//첫글자로 초기화
		checker[int(temp_alphabet - 'a')]++;//등장 횟수 1증가시켜두기

		for (int j = 1; j < word[i].size(); j++) {
			if (temp_alphabet == word[i][j]) {//이전 알파벳이랑 같은 알파벳이면
				continue;
			}
			else {//같지 않으면
				checker[int(word[i][j] - 'a')]++;
				temp_alphabet = word[i][j];
			}
		}

		//체커 벡터 검사로 그룹 단어 판별
		count++;//카운트 미리 하나 올려두고
		for (int k = 0; k < alphabet_num; k++) {
			if (checker[k] == 0 || checker[k] == 1) {
				continue;
			}
			else {
				count--;
				//cout << word[i]<<endl;//아닌놈 출력 판별
				break;
			}
		}

		//체커 벡터 초기화
		for (int k = 0; k < alphabet_num; k++) {
			checker[k] = 0;
		}
	}

	cout << count;

	return 0;
}