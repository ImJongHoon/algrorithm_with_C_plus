#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
하 좌 좌 좌
하
하
하
우 우 우 상

시작지점 기준
verti -1 번 하
hori - 1 번 우
verti -1 번 상
hori - 1 번 좌

시작지점 바뀔때마다
-2번씩 줄이기
*/

//하 우 위 좌
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
	int horizon;
	int vertical;
	int num;//돌리는 횟수
	int set_start;//시작지점 정하는 횟수
	int ny;
	int nx;
	int temp1, temp2;//이전값 이후값 저장하는 임시 변수

	//제한에 가로 세로 둘 중 크기가 더 작은쪽은 짝수임. 즉 가운데서 남는 숫자는 없음
	//원소 하나의 크기가 10의 8승까지 가능 == int형 선에서 처리 가능
	cin >> vertical;
	cin >> horizon;
	cin >> num;

	vector<vector<int>> arr(vertical, vector<int>(horizon));

	for (int y = 0; y < vertical; y++) {
		for (int x = 0; x < horizon; x++) {
			cin >> arr[y][x];
		}
	}
	
	//시작 지점 생성 횟수 = min / 2
	set_start = min(horizon, vertical) / 2;

	//n번 돌림
	for (int i = 0; i < num; i++) {
		//이게 시작 지점마다 한번 돌리기
		for (int j = 0; j < set_start; j++) {
			//시작 지점은 (j, j)가 된다
			ny = j;
			nx = j;
			temp1 = arr[ny][nx];
			for (int k = 0; k < 4; k++) {//방향 순서
				if (k % 2 == 0) {//하 상
					for (int l = 0; l < vertical - 1 - (j * 2); l++) {	
						//좌표 이동
						ny = ny + dy[k];
						nx = nx + dx[k];

						//이동한 후의 좌표가 덮어씌워지니 좌표값 저장
						temp2 = arr[ny][nx];

						//이동한 좌표에 이전값 저장
						arr[ny][nx] = temp1;

						//이전값 갱신
						temp1 = temp2;
					}
				}
				else if (k % 2 == 1) {//우 좌
					for (int l = 0; l < horizon - 1 - (j * 2); l++) {
						//좌표 이동
						ny = ny + dy[k];
						nx = nx + dx[k];

						//이동한 후의 좌표가 덮어씌워지니 좌표값 저장
						temp2 = arr[ny][nx];

						//이동한 좌표에 이전값 저장
						arr[ny][nx] = temp1;

						//이전값 갱신
						temp1 = temp2;
					}
				}
				else {
					cout << "error!";
				}
			}
		}
	}


	//출력
	for (int y = 0; y < vertical; y++) {
		for (int x = 0; x < horizon; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}