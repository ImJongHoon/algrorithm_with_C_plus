#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int horse;

	cin >> N;
	cin >> horse;

	vector<int> container(N);//마구간

	for(int i=0; i<N; i++){
		cin >> container[i];
	}

	sort(container.begin(), container.end());

	int lp = 1;//첫번째 마구간
	int rp = container[N-1];//마지막 마구간
	int mid;
	int count = 1;
	int index = 0;
	int answer = 0;

	while(lp < rp){
		mid = (lp + rp) / 2;//이만큼의 거리로 말들을 배치했을 때.
		index = 0;
		
		for(int i=1; i<N; i++){
			//container[0]에 이미 넣은걸로 시작
			if(container[i] - container[index] < mid){//mid가 사실상 떨어진 최소 거리
				continue;
			}
			else {
				index = i;
				count++; // 마구간에 넣은 말 증가
				if(count == horse){//다 집어넣었으면
					rp = mid;
					count = 1;
					answer = mid;
					break;
				}
			}	
		}

		if(count < horse){//다 못집어넣었으면
			lp = mid;
			count=1;
		}

	cout << mid;
	}

	cout << mid;

	return 0;
}