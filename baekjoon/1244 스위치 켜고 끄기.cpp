#include <iostream>
#include <vector>

using namespace std;

//남자는 배수의 상태를 변경
//여자는 좌우 대칭이면서 가장 먼 범위 스위치 모두 변경. 대칭이라는 건 스위치 상태도 포함한다.

struct student {
	int sex;
	int number;
};

void male(vector<int>&list, int selected_num, int switch_num) {
	for (int i = 0; i < switch_num; i++) {
		if ((i + 1)% selected_num == 0) {//특정 번호의 배수이면
			if (list[i] == 0) {
				list[i] = 1;
			}
			else {
				list[i] = 0;
			}
		}
	}
}

void female(vector<int>& list, int selected_num, int switch_num) {
	int count = -1;
	//주의: selected_num-1 에서 시작함
	//어디까지 대칭인가 count로 숫자 세고 (양 끝 out of range 검사)
	//가운데도 비교문에 들어감
	//시작전에도 out of range 한번 해주기? -> 이건 필요 없음. 길이 이하의 수가 주어져서.
	for (int i = 0; list[selected_num - 1 - i] == list[selected_num - 1 + i]; i++) {
		count++;
		//out of range 검사
		//cout << selected_num - 2 - i << " 또는 " << selected_num - i << endl;
		if (selected_num - 2 - i < 0 || selected_num + i >= switch_num) {
			break;
		}
	}
	//selected_num-1-count index에서 시작해서 count*2 + 1 횟수만큼 반복하면서 바꿔줌
	int start = selected_num - 1 - count;
	for (int i = 0; i < count * 2 + 1; i++) {
		if (list[start + i] == 0) {
			list[start + i] = 1;
		}
		else {
			list[start + i] = 0;
		}
	}
}

int main() {
	int switch_num = 0;
	int std_num;
	
	cin >> switch_num;

	vector<int> switch_list(switch_num, 0);

	for (int i = 0; i < switch_num; i++) {
		cin >> switch_list[i];
	}

	cin >> std_num;

	vector<student> std_list(std_num);

	for (int i = 0; i < std_num; i++) {
		cin >> std_list[i].sex;
		cin >> std_list[i].number;
	}

	int count = 1;

	//스위치 변환
	for (int i = 0; i < std_num; i++) {
		if (std_list[i].sex == 1) {
			male(switch_list, std_list[i].number, switch_num);
		}
		else if (std_list[i].sex == 2) {
			female(switch_list, std_list[i].number, switch_num);
		}
	}


	//출력
	for (int i = 0; i < switch_num; i++) {
		cout << switch_list[i] << " ";//띄기
		if (count % 20 == 0) {
			cout << endl;
		}
		count++;
	}

	return 0;
}