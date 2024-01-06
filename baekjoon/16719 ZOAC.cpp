#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	char alphabet;
	bool isWeighted;
	bool isPrint;
	int weight;
};

//문자열은 100자 밖에 안됨
int main() {
	string word;

	cin >> word;

	vector<info> opened_word(word.length());

	//초기화
	for (int i = 0; i < word.length(); i++) {
		opened_word[i].alphabet = word[i];
		opened_word[i].isWeighted = false;
		opened_word[i].isPrint = false;
		opened_word[i].weight = 0;
	}

	//문자열 정렬
	vector<char> sortedWord(word.length());

	for (int i = 0; i < word.length(); i++) {
		sortedWord[i] = word[i];
	}
	//정렬
	sort(sortedWord.begin(), sortedWord.end());

	//정렬된 순서에 따른 가중치 넣기
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < word.length(); j++) {
			if (sortedWord[i] == opened_word[j].alphabet && opened_word[j].isWeighted == false) {
				opened_word[j].isWeighted = true;
				opened_word[j].weight = i;//같은 알파벳이면 뒤에 있는 알파벳이 더 낮은 우선순위(높은숫자 받음)
				break;
			}
		}
	}

	int min = 101;
	int min_index = -1;

	//출력횟수
	for (int j = 0; j < word.length(); j++) {
		min = 987654321;
		for (int i = 0; i < word.length(); i++) {//최소값 구하기
			if (opened_word[i].isPrint == false && opened_word[i].weight < min) {
				min = opened_word[i].weight;
				min_index = i;
				//cout << opened_word[i].alphabet<<" / ";
			}
		}

		opened_word[min_index].isPrint = true;
		
		for (int i = 0; i < word.length(); i++) {
			if (opened_word[i].isPrint == true) {
				cout << opened_word[i].alphabet;
			}
		}
		cout << endl;

		//가중치 갱신 전 출력해보기
		/*
		for (int i = 0; i < word.length(); i++) {
			cout << opened_word[i].weight << " / ";
		}
		cout << endl;
		*/
	

		//가중치 갱신 (포인트된 지점 앞은 다 더해주기)
		for (int i = 0; i < min_index; i++) {
			opened_word[i].weight = opened_word[i].weight + word.length();
		}
		
	}

	return 0;
}