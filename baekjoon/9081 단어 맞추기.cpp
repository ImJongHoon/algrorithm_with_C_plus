#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string next(string word, int last_aes_index){
	string after_word;
	after_word = word.substr(last_aes_index+1);//index 이후부터 끝까지
	
	char min_str = after_word[0];//마지막 인덱스보다 크지만, 그중에 가장 작은값
	int min_str_index = 0;
	for (int i = 0; i < after_word.size(); i++) {
		if (after_word[i] > word[last_aes_index] && min_str> after_word[i]) {
			min_str = after_word[i];
			min_str_index = i;
		}
	}

	//문자열 다시 만들기
	char temp = after_word[min_str_index];
	after_word[min_str_index] = word[last_aes_index];
	word[last_aes_index] = temp;

	string front_word = word.substr(0, last_aes_index + 1);
	sort(after_word.begin(), after_word.end());

	return front_word + after_word;
}

int main() {
	int num;
	cin >> num;

	vector<string> word(num);

	for (int i = 0; i < num; i++) {
		cin >> word[i];
	}
	
	//주어진 단어의 다음 단어. 즉 단어의 사전순을 모두 찾을 필요는 없음.
	/*
	사전상 다음이란??
	맨 마지막 순차의 글자와, 그 이후에 마지막 순차의 글자와 가장 차이가 적은 바로 다음 글자와 순서를 바꾸는 것
	순서를 바꾸고, 이후 애들은 오름차순으로 만들어줘야함.
	*/

	//마지막 단어인지 찾기
	int length;
	bool isLast;
	int last_aes_index;//역사전순이 아닌 마지막 인덱스
	for (int i = 0; i < num; i++) {
		length = word[i].size();
		isLast = true;
		last_aes_index = -1;
		for (int j = 0; j < length - 1; j++) {
			if (word[i][j] >= word[i][j+1]) {//항상 다음보다 이전이 크거나 같으면
				continue;
			}
			isLast = false;
			last_aes_index = j;
		}
		
		//출력
		if (isLast == true) {
			cout << word[i] << '\n';
		}
		else {
			cout << next(word[i], last_aes_index)<<'\n';
		}

	}

	return 0;
}