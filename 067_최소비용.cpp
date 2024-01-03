//해당 경로의 도착 지점과 가중치를 둘 다 표기하기 위해
//pair나 구조체를 사용해야한다.
//.push_back으로 사용.
#include <iostream>
#include <vector>

using namespace std;

int node_num;

struct edge {
	int arrive;
	int weight;
};
vector<int> visited;

int min_weight = 99999;

//인접행렬 사용
void dfs(int y, vector<vector<edge>>& edge_info, int weight) {
	if (y == node_num) {
		if (weight < min_weight) {
			min_weight = weight;
		}
	}
	else {
		for (int i = 0; i < edge_info[y - 1].size(); i++) {
			if (visited[edge_info[y - 1][i].arrive - 1] == 1) {

			}
			else {
				weight = weight + edge_info[y - 1][i].weight;
				visited[edge_info[y - 1][i].arrive -1] = 1;

				dfs(edge_info[y - 1][i].arrive, edge_info, weight);
			
				weight = weight - edge_info[y - 1][i].weight;
				visited[edge_info[y - 1][i].arrive - 1] = 0;
			}
		}
	}
}

int main() {
	int edge_num;

	cin >> node_num >> edge_num;

	vector<vector<edge>> edge_info(node_num);
	visited = vector<int>(node_num, 0);

	int a, b, c;
	edge info;
	for (int i = 0; i < edge_num; i++) {
		cin >> a >> b >> c;
		info.arrive = b;
		info.weight = c;

		edge_info[a-1].push_back(info);
	}

	visited[0] = 1;
	dfs(1, edge_info, 0);

	cout << min_weight;

	return 0;
}