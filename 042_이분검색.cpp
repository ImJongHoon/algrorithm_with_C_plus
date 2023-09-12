#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int M;
	int lp = 0;//왼쪽 인덱스
	int rp;
	int mid;

	cin >> N;
	cin >> M;
	rp = N - 1;
	mid = N / 2;

	vector<int> num(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	while (1) {
		if (num[mid] == M) {
			break;
		}
		else if (num[mid] > M) {
			rp = mid - 1;
			mid = (rp + lp) / 2;
		}
		else if (num[mid] < M) {
			lp = mid + 1;
			mid = (rp + lp) / 2;
		}
	}

	cout << mid+1;

	return 0;
}