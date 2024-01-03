#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum =0;
int sum =0;

//인자로 횟수
void dfs(int num, int now, vector<int>& tallA, vector<int>& tallB, int sum, int side, int p) {
	if (num <= now) {
		cout << sum << endl;
		if (max_sum < sum) {
			max_sum = sum;
		}
	}
	else {

		sum = sum + tallA[now];
		if (side == 1) {
			sum = sum - p;
		}
		dfs(num, now+1, tallA, tallB, sum, 1, p);

		
		sum = sum - tallA[now] + tallB[now];
		if (side == 2) {
			sum = sum - p;
		}
		dfs(num, now+1, tallA, tallB, sum, 2, p);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("sample_input.txt", "r", stdin);

	/*
	   아래 코드는 입출력수행 프로세스 속도를 향상시키기 위한 명령어입니다.
	   아래 코드가 실행될 경우 scanf와 cin을 혼용해서 사용할 시 테스트 케이스가 정상적으로 입력되지 않을 수 있으니 유의하십시오.
	*/
	std::ios::sync_with_stdio(false);

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		max_sum = 0;
		sum = 0;
		//화분 갯수
		int num;
		//작아지는 차이
		int p;
		cin >> num;
		cin >> p;
		vector<int> tallA(num, 0);
		vector<int> tallB(num, 0);

		for (int i = 0; i < num; i++) {
			cin >> tallA[i];
		}
		for (int i = 0; i < num; i++) {
			cin >> tallB[i];
		}

		dfs(num, 0, tallA, tallB, 0, 0 ,p);

		// 표준출력(화면)으로 답안을 출력합니다.
		cout << "#" << test_case << " " << max_sum << endl;
	}

	return 0;
}
