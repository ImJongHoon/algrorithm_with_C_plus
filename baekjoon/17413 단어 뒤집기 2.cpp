#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	//버퍼에 넣어주는 과정 생략
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	string s;
	string result_s;
	stack<char> temp_stack;
	int lparen = 0;

	//공백포함 문자열 입력받기
	getline(cin, s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '>') {//괄호 닫히는지검사
			result_s.push_back(s[i]);
			lparen = 0;
		}
		else if (lparen == 1) {//괄호 안이라는 뜻. 결과값에 뒤집지 않은거 넣어주기.
			result_s.push_back(s[i]);
			continue;
		}
		else if (s[i] == '<') {
			//이 앞에 글자가 있었다면
			while (!temp_stack.empty()) {//스택이 빌때까지
				result_s.push_back(temp_stack.top());
				temp_stack.pop();
			}
			result_s.push_back(s[i]);
			lparen = 1;
			continue;
		}
		//괄호 밖의 띄어쓰기인 경우 여태까지 stack에 담은 단어들 전부 pop
		else if (s[i] == ' ') {
			while (!temp_stack.empty()) {//스택이 빌때까지
				result_s.push_back(temp_stack.top());
				temp_stack.pop();
			}
			result_s.push_back(s[i]);
		}
		else {//남은 문자들은 들어오면
			temp_stack.push(s[i]);
		}
	}

	//마지막 \0 오고 나서도
	while (!temp_stack.empty()) {//스택이 빌때까지
		result_s.push_back(temp_stack.top());
		temp_stack.pop();
	}

	cout << result_s;

	return 0;
}