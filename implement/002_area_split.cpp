//0. y와 X의 위치 변경?
//1. BFS 사용 이유
//2. 방문처리
//3. 이중 반복문을 사용할 때, 밖이 y, 안이 x로
//4. 이중 vector.
//5. STL queu와 pair <<< 공부 필요
//6. 방문처리 하나로 BFS와 중복되는 영역 검사 둘 다 없도록 만들어주는 코드
//7. 코드를 효율적으로 짜는 배열. 배열을 선언하고 반복문을 돌리면서 값을 하나하나 따와서 넣는 방법.
//8. 생각이 막히면 뭘 하고 있었는지 다시 숲을 확인하기.
//9. out of memory.
//10. 배열의 이름과 같이 vector의 이름도 곧 주소이다.

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info{
    int y;
    int x;
};

vector<vector<bool>> visited;

//반복문 돌리면서 대입할 값 배열로 정리
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

//시작 지점을 인자로 받음.
int BFS(vector<vector<int>>&board, int y, int x, int n){
    visited[y][x] = true;

    queue<Info> q;
    //시작 지점을 큐에 넣고
    q.push({y, x});

    int area_size = 1;
    //반복문이 끝날때까지 BFS를 돌겠다.
    while(!q.empty()){
        Info current_value = q.front();//맨앞 임시저장하고
        q.pop();//맨 앞 삭제해주고

        for(int dir=0; dir<4; dir++){
            int ny= current_value.y + dy[dir];
            int nx= current_value.x + dx[dir];

            //인접한 애가 1인지 검사하고
            //out of memory도 검사
            //조건을 board[ny][nx] == 1 이걸로 만들어서 if문 안에서 도는게 아니라,
            //큐에 추가하지 말아야할 조건을 만들기.
            if(ny < 0 || nx<0 || ny>=n || nx>=n || visited[ny][nx] || board[ny][nx] == 0){
                continue;//큐에 넣지 말것.
            }

            //이후에 큐에 추가한다.
            q.push({ny, nx});
            area_size++;
            visited[ny][nx] = true;
        }
    }

    return area_size;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));//두번째 인자가 요소 하나하나를 뭐로 초기화할지임.
    visited = vector<vector<bool>>(n, vector<bool>(n));

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    int count = 0;
    vector<int> area_sizes;

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(board[y][x] == 1 && visited[y][x] == false){
                count++;
                area_sizes.push_back(BFS(board, y, x, n));
                
            }
        }
    }
    cout << count << "\n";

    sort(area_sizes.begin(), area_sizes.end());

    for(int i=0; i<count; i++){
        cout<< area_sizes[i] << ' ';
    }

    return 0;
}