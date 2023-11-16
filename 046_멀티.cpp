#include <iostream>
#include <vector>

using namespace std;

int a[2000];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int num;//thread 크기
	int t;//정전시간
	int sum = 0;//전체 작업량

	cin >> num;

	vector<int> thread(num);

	for (int i = 0; i < num; i++) {
		cin >> thread[i];
		sum = sum + thread[i];
	}
	cin >> t;//t까지 일을 하고 그 다음에 정전

	//정전 전에 일이 끝나는가?
	if (t >= sum) {
		cout << -1;
	}
	else {
		//t+1번째에 할 일
		int count = 0;
		for (int i = 0; i < t + 1;) {
			if (thread[count % num] > 0) {
				if (i == t) {//정전 다음에 할 일
					cout << (count % num) + 1;
				}
				thread[count % num] = thread[count % num] - 1;
				count++;
				i++;//한번 일 처리함
			}
			else {
				count++;
			}
		}
	}
	
}