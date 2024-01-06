#include <iostream>
#include <algorithm>

using namespace std;

struct info {
	int start;
	int end;
};

//일정 하나의 세로 길이1, 하루 길이1
//날짜는 쭉 있는데 일정이 겹쳐져서 아래로 표시될 수 있음
//연속된 두 일자에 1개 이상의 일 있으면 일이 연속
//연속되면 다 감싸야됨
int main() {
	int num;
	cin >> num;

	int calander[365] = { 0 };

	info plan[1000];

	for (int i = 0; i < num; i++) {
		cin >> plan[i].start;
		cin >> plan[i].end;
	}

	//가로가 늘어나는 경우
	//세로가 늘어나는 경우
	//달력 배열에 기간만큼 입력해서 최대 값이 세로가 되도록
	int start_index;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < plan[i].end - plan[i].start + 1; j++) {
			start_index = plan[i].start - 1;
			calander[start_index+j]++;
		}
	}

	int area = 0;
	int continue_count = 0;//연속되는 날짜
	int max_plan = 0;//겹쳐있는 일정 수

	for (int day = 0; day < 365; day++) {
		if (calander[day] != 0) {//일정이 있으면
			continue_count++;//일정 지속일 증가
			max_plan = max(max_plan, calander[day]);//최대값
		}
		else if (calander[day] == 0) {//일정이 없거나 끊겼으면
			area = area + (continue_count * max_plan);
			
			max_plan = 0;
			continue_count = 0;
		}
	}

	//마지막까지 일정이 있는 경우도 포함해서
	area = area + (continue_count * max_plan);

	//면적
	cout << area;

	return 0;
}