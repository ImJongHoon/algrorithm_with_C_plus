#include <iostream>
#include <vector>

using namespace std;

int result = 0;

void dfs(int num, vector<int>& list, int n, int index, int cal) {
	if (n <= index) {
		//마지막 노드 도달
		//cout << cal << endl;
		if (cal == num) {
			result++;
		}
	}
	else {
		//해당 인덱스를 사용하지 않는 경우
		dfs(num, list, n, index+1, cal);
		
		//해당 인덱스를 더하는 경우
		cal = cal + list[index];
		dfs(num, list, n, index + 1, cal);
		//원상복귀
		cal = cal - list[index];


		//해당 인덱스를 빼는 경우
		cal = cal - list[index];
		dfs(num, list, n, index + 1, cal);

	}
}

int main() {
	int n;
	int num;

	cin >> n;
	cin >> num;

	vector<int> list(n);

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	dfs(num, list, n, 0, 0);

	cout << result;

	return 0;
}