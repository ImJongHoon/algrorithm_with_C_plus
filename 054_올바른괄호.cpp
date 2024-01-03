#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int a[2000];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	stack<char> s;
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(a[i]);
		}
		else {//닫는 괄호
			if (s.empty() == true) {
				printf("NO");
				return 0;
			}
			else s.pop();//아니면 그냥 pop
		}
	}
	if (s.empty()) {
		cout << "YES"<<endl;
	}
	else {
		cout << "NO"<<endl;
	}

	return 0;
}