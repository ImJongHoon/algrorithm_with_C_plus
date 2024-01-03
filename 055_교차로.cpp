#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//기차운행
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int num;

	cin >> num;

	vector<int> start(num);

	for (int i = 0; i < num; i++) {
		cin >> start[i];
	}
	
	vector<int> end(start.size());

	//벡터 복사 후 정렬
	copy(start.begin(), start.end(), end.begin());
	sort(end.begin(), end.end());

	//출력해줄 string
	string result;

	//스택 선언
	stack<int> s;
	int count = 0;
	for (int i = 0; i < num; i++) {
		s.push(start[i]);
		result.push_back('P');

		while (s.empty() == false && (s.top() == end[count])) {
			s.pop();
			result.push_back('O');
			count++;
		}
	}


	if (s.empty() == false) {
		cout << "impossible";
	}
	else {
		cout << result;
	}


	return 0;
}