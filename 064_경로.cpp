#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> check;
int cnt = 0;

int START_NODE = 1;

void DFS(int vertex, int last_vertex) {
	if (vertex == last_vertex) {
		cnt++;
	}
	else {

		for (int i = 0; i < last_vertex; i++) {
			if (check[i] == 0 && map[vertex - 1][i] == 1) {
				check[i] = 1;
				DFS(i + 1, last_vertex);
				check[i] = 0;
			}
			else {

			}
		}
	}
}

int main() {
	int node;
	int edge_num;

	cin >> node >> edge_num;

	//인접행렬 구하기
	map = vector<vector<int>>(node, vector<int>(node, 0));
	check = vector<int>(node, 0);

	int start;
	int end;

	for (int i = 0; i < edge_num; i++) {
		cin >> start >> end;
		map[start - 1][end - 1] = 1;
	}

	check[START_NODE - 1] = 1;
	DFS(START_NODE, node);

	cout << cnt;

	return 0;
}