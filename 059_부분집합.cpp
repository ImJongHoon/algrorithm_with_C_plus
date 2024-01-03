#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n=3;
int ch[10];

void dfs(int L) {
	if (L == n + 1) {//마지막 숫자 도달 시(마지막 트리 계층)
		for (int i = 0; i < n; i++) {
			if (ch[i] == 1) {
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	else {
		ch[L-1] = 1;
		dfs(L + 1);

		ch[L-1] = 0;
		dfs(L + 1);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	dfs(1);

	return 0;
}