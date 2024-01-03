#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

vector<int> visited;


//인접행렬 사용
void bfs(int node) {
	visited[node - 1] = 0;

	queue<int> q;
	q.push(node);

	int curren_value;
	int current_node;

	while (q.empty() == false) {
		curren_value = q.front();
		q.pop();

		for (int i = 0; i < graph[curren_value - 1].size(); i++) {
			current_node = graph[curren_value - 1][i];
			if (visited[current_node - 1] == 0) {
				visited[current_node - 1] = visited[curren_value-1]+1;
				q.push(current_node);
			}
		}
	}
}

int main() {
	
	int node_num;
	int edge_num;

	cin >> node_num >> edge_num;

	graph = vector<vector<int>>(edge_num);
	visited = vector<int>(node_num, 0);

	int start_node;
	int end_node;
	for (int y = 0; y < edge_num; y++) {
		cin >> start_node >> end_node;

		graph[start_node - 1].push_back(end_node);
	}

	bfs(1);

	for (int i = 1; i < node_num; i++) {
		cout << i+1 << " : " << visited[i] << "\n";
	}

	return 0;
}