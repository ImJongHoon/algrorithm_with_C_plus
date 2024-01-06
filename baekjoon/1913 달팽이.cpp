#include <iostream>
#include <vector>

using namespace std;

//상 우 하 좌 순서
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
    int N;
    int ny;//현재 좌표
    int nx;
    int search_num;
    int search_y, search_x;//출력해줄 좌표.
    int count;

    cin >> N;
    cin >> search_num;
    vector<vector<int>> grid(N, vector<int>(N, 0));

    ny = N / 2;
    nx = N / 2;

    grid[ny][nx] = 1;//1 대입
    search_y = ny;
    search_x = nx;

    count = 2;

    for (int i = 0; count <= N * N; i++) {
        for (int j = 0; j < (i / 2) + 1; j++) {//방향전환
            ny = ny + dy[i % 4];
            nx = nx + dx[i % 4];
            grid[ny][nx] = count;

            if (count == search_num) {
                search_y = ny;
                search_x = nx;
            }
            count++;
            if (count > N * N) {
                break;
            }
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
    cout << search_y + 1 << " " << search_x + 1;

    return 0;
}