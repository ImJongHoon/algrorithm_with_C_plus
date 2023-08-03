#include <iostream>
#include <vector>

using namespace std;

//바닥은 항상 막혀있음.
//즉 아래의 높이도 구해야 함

//생구현
//고이는 기준 높았다가 낮았다가 다시 높아지고 여기서 다시 낮아지던지 초반에 높았던곳 높이보다 더 높아지던지

int calcWater(vector<int>& land, int left_max_index, int right_max_index, int h) {
	int water=0;

	for (int i = left_max_index+1; i < right_max_index; i++) {
		if (land[i] < h) {//현재벽이 기준 높이보다 낮으면?
			water++;
		}
	}

	return water;
}

int main() {
	int height;
	int width;

	cin >> height;
	cin >> width;

	vector<int> land(width, 0);

	for (int i = 0; i < width; i++) {
		cin >> land[i];
	}

	//왼쪽 최대 vs 오른쪽 최대
	//오른쪽 최대가 왼쪽 최대보다 크거나 같아지는 경우: 지금까지 물 계산하고 최대 높이 다시 갱신
	//오른쪽 최대가 왼쪽 최대보다 끝까지 작은 경우: 오른쪽 최대가 기준이 되어 그 아래만 물을 카운팅
	//5113112 인 경우와 51131125 인 경우를 어떻게 구별해야 함?

	//투포인터로 생각해?
	int max_height = -1;
	int left_max_index = -1;//안나오면 outofindex로 출력하도록
	int right_max_index = -1;
	

	//최대 땅 높이 구하자
	for (int i = 0; i < width; i++) {
		if (land[i] > max_height) {
			max_height = land[i];
		}
	}

	int count_wall = 0;//벽의 갯수
	int total = 0;//물의 양

	for (int i = max_height; i >= 0; i--) {//최대 높이 줄어듦
		//전처리
		left_max_index = -1;//안나오면 outofindex로 출력하도록
		right_max_index = -1;
		count_wall = 0;

		for (int j = 0; j < width; j++) {
			if (land[j] >= i && left_max_index == -1) {//비교할 높이보다 크면서 처음이면
				left_max_index = j;
			}
			else if (land[j] >= i) {//그 다음으로 오는건 계속 덮어쓰기
				right_max_index = j;
			}	
		}
		if (left_max_index != -1 && right_max_index != -1) {
			total = total + calcWater(land, left_max_index, right_max_index, i);
		}
	}

	cout << total;

	return 0;
}

//오히려 발상을 세로로?
//1. 최대 높이 구하기
//2. 최대 높이부터 시작해서 1씩 빼서 높이h 검사
//3. 그 높이 h를 기준으로 시작과 끝 인덱스를 구하기.(그 높이h보다 크거나 같으면 다 인덱스가 될 수 있음
//4. 그 인덱스 사이에서 h보다 작은 지역에는 물이 무조건 고임(해당 h 층만 생각함 아래는 x)
//5. total에 더하고 작아지기 반복