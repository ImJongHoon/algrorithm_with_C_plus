#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int num;
	
	scanf("%d", &num);
	
	vector<vector <int>>v(num,vector<int>(num, 0));
	
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			
		}
	}
	return 0;
}
//정사각형의 행렬
//영역의 갯수(떨어져 있음을 판별해야 함.)
//영역의 크기(1이 몇개 붙어있는지를 확인해야 함.)
//영역이 없으면 0하고 끝나야 함.

//
//if(v[i-1][j]<=v[i][j] && v[i-1][j]>=v[i][j]){
//영역 -1
//영역 크기 =+ v[i][j+1] - v[i][j]
//}