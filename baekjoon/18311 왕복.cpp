//시작 14:55
//끝 
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int course_num;
	cin >> course_num;

	vector<int> course(course_num, 0);

	long long int now_position;
	cin >> now_position;

	//거리를 저장함
	for (int i = 0; i < course_num; i++) {
		cin >> course[i];
	}

	//저장된 트랙 거리 확인
	/*for (int i = 0; i < course_num * 2; i++) {
		cout << course[i] << " ";
	}
	cout << endl;
	*/

	//몇번째 배열에 속하는지 구하기
	int track = 0;
	bool isArrived = false;
	for (int i = 0; i < course_num; i++) {
		track++;
		now_position = now_position - course[i];

		//0이면 한번 더. 음수일때만 탈출
		if (now_position < 0) {
			isArrived = true;
		}

		if (isArrived == true) {
			break;
		}
	}
	//왕복 해야하는 크기면
	if (isArrived == false) {
		for (int i = course_num - 1; i >=0 ; i--) {
			track++;
			now_position = now_position - course[i];

			//0이면 한번 더. 음수일때만 탈출
			if (now_position < 0) {
				isArrived = true;
			}

			if (isArrived == true) {
				break;
			}
		}
	}

	//끝을 찍고 오는게 아니면
	if (track <= course_num) {
		cout << track;
	}
	else if (track > course_num) {
		track = track - course_num;//몇트랙 초과했는지 세주고
		track = course_num - (track - 1);//초과한 트랙-1만큼 거꾸로가는거 확인
		cout << track;
	}

	return 0;
}