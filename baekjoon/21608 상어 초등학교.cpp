#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//그냥 구현해도 시간초과가 안난다 판단되면 알고리즘 없이 구현하는 편이다.
// 
//좌표 저장해둘때 사용
struct coordinate {
    int y;
    int x;
};

//반복문으로 탐색할때 이용
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

//순회를 하면서 저장할 위치의 학생과 빈칸수를 기억하고,
//학생수가 많아지면 업데이트, 학생수가 같으면 빈칸수 보고 또 업데이트 이런 식으로.
//또한 순회 방향을 위에 행부터 차례대로 하면서 같은 값은 패스해주면 자연스럽게 행과 열을 초기화한다.
coordinate findSeat(vector<vector<int>>& classSeat, int num, int self, int std1, int std2, int std3, int std4) {

    //초기화해주지 않으면 반드시 오류가 난다.
    coordinate fitSeat = { num, num };

    //이 친구 구조체로 묶기.
    int favorNum = 0;
    int emptyNum = 0;
    int maxFavorNum = 0;
    int maxEmptyNum = 0;
    int tempSeat;

    for (int y = 0; y < num; y++) {
        for (int x = 0; x < num; x++) {
            //초기화
            emptyNum = 0;
            favorNum = 0;

            //이미 있는 자리면 다음으로
            if (classSeat[y][x] != 0) {
                continue;
            }

            //상하좌우 탐색문
            for (int i = 0; i < 4; i++) {
                //변환한 좌표
                int ny = y + dy[i];
                int nx = x + dx[i];

                //out of memory 검사
                if (ny >= num || ny < 0 || nx >= num || nx < 0) {
                    continue;
                }

                tempSeat = classSeat[ny][nx];

                if (tempSeat == 0) {//빈자리면
                    emptyNum++;
                }
                else if (tempSeat == std1 || tempSeat == std2 || tempSeat == std3 || tempSeat == std4) {//호감 친구중 한명이면
                    favorNum++;
                }
            }

            if (favorNum > maxFavorNum) {
                maxFavorNum = favorNum;
                maxEmptyNum = emptyNum;
                fitSeat.y = y;
                fitSeat.x = x;
            }
            else if (favorNum == maxFavorNum && emptyNum > maxEmptyNum) {
                maxEmptyNum = emptyNum;
                fitSeat.y = y;
                fitSeat.x = x;
            }
            else if (favorNum == maxFavorNum && emptyNum == maxEmptyNum) {
                //정답의 결과가 나오지 않으니까, 안전한 코드 짜는 게 좋다.
                //같은경우 행과 열을 비교하는
                //야매는 아니지만 사실상 리스크가 있다. 
                if (fitSeat.x < x) {
                    fitSeat.y;
                    fitSeat.x;
                }
                else if (fitSeat.x == x && fitSeat.y < y) {//유지
                    fitSeat.y;
                    fitSeat.x;
                }
                else {
                    fitSeat.y = y;
                    fitSeat.x = x;
                }
            }
        }
    }

    return fitSeat;
}

//좌표 하나의 만족도만 출력하면 됨
int calSatisfy(vector<vector<int>>& classSeat, vector<vector<int>>& favorateFreind, int num, int y, int x) {

    int score = 0;
    int count = 0;
    int tempSeat;
    int std1, std2, std3, std4;

    //해당 좌표의 주인과 친구들 누구인지 찾기
    for (int i = 0; i < num * num; i++) {
        if (classSeat[y][x] == favorateFreind[i][0]) {
            std1 = favorateFreind[i][1];
            std2 = favorateFreind[i][2];
            std3 = favorateFreind[i][3];
            std4 = favorateFreind[i][4];
            break;
        }
    }

    //상하좌우 탐색문
    for (int i = 0; i < 4; i++) {
        //변환한 좌표
        int ny = y + dy[i];
        int nx = x + dx[i];

        //out of memory 검사
        if (ny >= num || ny < 0 || nx >= num || nx < 0) {
            continue;
        }

        tempSeat = classSeat[ny][nx];

        if (tempSeat == std1 || tempSeat == std2 || tempSeat == std3 || tempSeat == std4) {//호감 친구중 한명이면
            count++;
        }
    }
    //10분의 1은 0이 될 것
    score = score + pow(10, count - 1);

    return score;
}


int main() {
    int num = 0;
    cin >> num;

    int stdNum = num * num;

    //만족하는 친구 담는 변수
    vector<vector<int>> favorFriend(stdNum, vector<int>(5));
    vector<vector<int>> classSeat(num, vector<int>(num, 0));

    //학생 index 정렬하면 안됨. 그 순서대로 자리 앉힘.
    //첫번째 인덱스가 해당 학생
    for (int i = 0; i < stdNum; i++) {
        //입력받음
        for (int j = 0; j < 5; j++) {
            cin >> favorFriend[i][j];
        }
    }


    coordinate seat;

    //학생수만큼 반복
    for (int i = 0; i < stdNum; i++) {
        seat = findSeat(classSeat, num, favorFriend[i][0], favorFriend[i][1], favorFriend[i][2], favorFriend[i][3], favorFriend[i][4]);
        classSeat[seat.y][seat.x] = favorFriend[i][0];//input에서 받은 자기 자신
    }

    //출력
    //for (int y = 0; y < num; y++) {
    //     for (int x = 0; x < num; x++) {
    //         printf("%d ", classSeat[y][x]);
    //     }
    //     printf("\n");
    //}

    int total = 0;

    for (int y = 0; y < num; y++) {
        for (int x = 0; x < num; x++) {
            total = total + calSatisfy(classSeat, favorFriend, num, y, x);
        }
    }

    cout << total;

    return 0;
}