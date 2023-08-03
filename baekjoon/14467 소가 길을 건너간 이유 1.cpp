#include <iostream>
#include <vector>

using namespace std;

int main() {
	//input을 너무 다 저장하려고 할 필요 없음
	//각 관찰은 소의 번호/소의 위치 이렇게 이루어짐
	//관찰 횟수 num
	int num = 0;
	//배열은 벡터와 달리 {-1} 이런식으로 써도 첫 인덱스만 -1이고 나머지 다 0임
	vector<int> cow(10, -1);

	int count = 0;
	int cow_num;
	int cow_where;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cow_num;
		cin >> cow_where;

		if (cow[cow_num-1] == -1) {
			cow[cow_num-1] = cow_where;
		}
		else if(cow[cow_num - 1] != -1) {
			if (cow_where != cow[cow_num-1]) {
				count++;
			}
			cow[cow_num-1] = cow_where;
		}
	}

	cout << count;

	return 0;
}