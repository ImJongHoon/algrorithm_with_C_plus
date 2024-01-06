//시작 2시 46분
// 1차: 시간초과
// 2차: 3중 for문 -> 2중 for문 : 시간초과
// 3차: 단순 반복문 (5시 5분)
//끝
#include <iostream>
#include <vector>

using namespace std;

int cow[200000];
int tricks[200000];
int values[200000];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int num;
	int trick_num;
	
	cin >> num;
	cin >> trick_num;

	for (int i = 0; i < num; i++) {
		cin >> cow[i];
	}
	
	for (int i = 0; i < trick_num; i++) {
		cin >> tricks[i];
	}

	//아무것도 건들이기 전, 4개씩 계산한 값들 구하기
	values[0] = cow[0] * cow[1] * cow[2] * cow[3];
	for (int i = 1; i < num; i++) {//계산
		values[i] = (values[i-1] / cow[i-1]) * cow[(i + 3) % num];
	}


	//하나를 바꾸면 걔를 포함하는 4개의 값을 두번 빼준게 답.
	//(부호가 바뀌었으므로)
	//시작값 구하기
	int total = 0;
	for(int i=0; i<num; i++){
		total = total + values[i];
	}

	int changed_value;//총 변화량
	int index;//장난친 인덱스
	for (int i = 0; i < trick_num; i++) {
		changed_value = 0;
		//총변화량 구하면서 동시에 값 네개 바꿔주기
		index = tricks[i] - 1;
		for (int j = 0; j < 4; j++) {
			//?: 저장된 덧셈의 index는 해당 지점을 시작으로해서 더해줌
			if (index - j < 0) {
				changed_value = changed_value + values[num + (index - j)];
				values[num + (index - j)] = -values[num + (index - j)];//거꾸로 읽기
			}
			else {
				changed_value = changed_value + values[index - j];
				values[index - j] = -values[index - j];
			}
			
		}
		
		total = total - (2 * changed_value);
		cout << total << '\n';
	}

	return 0;
}