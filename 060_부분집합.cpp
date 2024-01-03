#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int check = 0;

void dfs(int n, int layer, vector<int>& num, int sum1, int sum2) {
	if(check == 1){
        return;
    }
    if (n <= layer) {
		//cout << "sum1: " << sum1 << endl;
		//cout << "sum2: " << sum2 << endl;

		if (sum1 == sum2) {
			check = 1;
		}
	}
	else {
		sum1 = sum1 + num[layer];
		dfs(n, layer+1, num, sum1, sum2);

		sum1 = sum1 - num[layer];
		sum2 = sum2 + num[layer];
		dfs(n, layer + 1, num, sum1, sum2);
	}
}

int main() {
	
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	dfs(n, 0, num, 0, 0);

	if (check == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}