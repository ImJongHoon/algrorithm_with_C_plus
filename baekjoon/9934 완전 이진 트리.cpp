#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct info {
	int num;
	bool isRead = false;
};

int main() {
	int depth;
	cin >> depth;

	int length;//받는 숫자 길이
	length = pow(2, depth) - 1;

	vector<info> numArr(length);

	for (int i = 0; i < length; i++) {
		cin >> numArr[i].num;
	}

	int term = (length / 2) + 1;
	int	point = 0;//몇번째 숫자인지임. index아님.
	while (term != 0) {
		point = point + term;
		if (point > length) {
			term = term / 2;
			cout << endl;
			point = 0;
			continue;
		}

		if (numArr[point - 1].isRead == false) {
			cout << numArr[point - 1].num << " ";
			numArr[point - 1].isRead = true;
		}
	}

	return 0;
}