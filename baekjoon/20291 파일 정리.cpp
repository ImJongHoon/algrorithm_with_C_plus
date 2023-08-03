#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//단순 추출, 정렬, 카운팅, 출력으로 분리

struct extendInfo {
	string extName;
	int asci[100];//첫글자 같으면? 이론상 100번째 글자까지 같으면?
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int dot_index;
	int num;

	cin >> num;

	//string fileName[50000]은 안됨. 스택 영역을 초과해서 힙 영역으로 할당하라고 함
	vector<string> fileName(num);
	vector<string> dotAfter(num);

	for (int i = 0; i < num; i++) {
		cin >> fileName[i];
	}
	for (int i = 0; i < num; i++) {
		dot_index = fileName[i].find(".");
		//substr 문자열 빼기. 특정 위치부터 끝까지
		//두번째 인자를 주면 위치부터 몇번째까지인지 출력 가능
		dotAfter[i] = fileName[i].substr(dot_index+1);
	}

	//sort함수 없이 사전순 정렬은??? 첫번째 비교 두번째비교 이거 어떻게 코딩함?
	sort(dotAfter.begin(), dotAfter.end());

	//즉시출력하자. 뒤와 다르면 출력, 끝까지 오면 출력
	int count = 1;
	string temp_ext = dotAfter[0];
	for (int i = 1; i < num; i++) {
		if (temp_ext == dotAfter[i]) {
			count++;
		}
		else {
			cout << temp_ext << " " << count << endl;
			temp_ext = dotAfter[i];
			count = 1;
		}
	}
	//마지막 출력
	cout << temp_ext << " " << count << endl;

	return 0;
}