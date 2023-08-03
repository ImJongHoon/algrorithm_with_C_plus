#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; int M;
	vector<int> player;

	while (1) {
		cin >> N;
		cin >> M;
		vector<int> player(10000, 0);

		if (N == 0 || M == 0) {
			break;
		}

		vector<vector<int>> ranking(N, vector<int>(M,0));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> ranking[y][x];
			}
		}

		int index;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				index = ranking[y][x] -1;
				player[index]++;
				//cout << index << "증가" << endl;
			}
		}

		int max = 0;
		int second_max = 0;
		for (int i = 0; i < 10000; i++) {
			if (player[i] >= max) {//같은 것까지 걸려야 second_max랑 같아지는 거 방지 가능
				//최대값 갱신하면서 두번째 값에 들어있는 것도 갱신
				if (max > second_max) {
					second_max = max;
				}
				max = player[i];
			}
			else if (player[i] > second_max) {
				second_max = player[i];
			}
		}

		for (int i = 0; i < 10000; i++) {
			if (second_max == player[i]) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
	}

	return 0;
}