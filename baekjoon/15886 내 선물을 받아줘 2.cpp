//시작 14:16
//32분~잠
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int width;
	cin >> width;

	vector<char> board(width);
	for (int i = 0; i < width; i++) {
		cin >> board[i];
	}
	//E가 나오면 +1(오른쪽으로 한칸)
	//W가 나오면 -1(왼쪽으로 한칸)

	int min_present = 0;
	
	//WEWEWE WE  EW로 변경. OW와 EO도 각각 O로 변경
	//WEEW EWWE
	vector<char> result1;
	char before=' ';
	for (int i = 0; i < width; i++) {
		if (before == board[i]) {
			continue;
		}
		result1.push_back(board[i]);
		before = board[i];
	}
	/*
	for (int i = 0; i < result1.size(); i++) {
		cout << result1[i];
	}
	cout << '\n';
	*/

	vector<char> result2;
	result2.push_back(result1[0]);
	before = result1[0];
	for (int i = 1; i < result1.size(); i++) {
		if (before == 'E' && result1[i] == 'W') {
			continue;
		}
		result2.push_back(result1[i]);
		before = result1[i];
	}

	/*
	for (int i = 0; i < result2.size(); i++) {
		cout << result2[i];
	}
	cout << '\n';
	*/

	min_present = result2.size();
	cout << min_present;

	return 0;
}