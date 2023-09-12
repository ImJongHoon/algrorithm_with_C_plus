#include <iostream>
#include <vector>
#include <algorithm>

//이분 검색 알고리즘을 사용하는 알고리즘 문제는 '결정 알고리즘'이 있다.
//결정 알고리즘이란 답이 맞는가 아닌가 계속 판단해야하는 문제라고 함.
//나랑 다르게 결정 알고리즘이란, 답이 가능한 범위를 좁혀나가면서 대입하는 방법이다. 

using namespace std;

int main() {
	int dvdNum;
	int groupNum;

	cin >> dvdNum;
	cin >> groupNum;

	vector<int> dvdTime(dvdNum, 0);

	for(int i=0; i<dvdNum; i++){
		cin >> dvdTime[i];
	}
	//최소한의 크기 = 각 그룹마다 최대한 많이 담아야함.
	//순차적으로 담아야 함.
	//이미 정렬이 되어 있음.
	//불변: 첫번째 그룹에는 첫번째 숫자부터 담긴다.
	//모든 그룹에 하나씩은 넣어야 최소가 된다.
	//약 1 / dvdNum 지점들을 찾으면 됨.
	int sum=0;
	for(int i=0; i<dvdNum; i++){
		sum = sum + dvdTime[i];
	}
	int average;
	average = sum / groupNum;

	int answer = 0;
	//뒤에서부터 더해서 넘는 그 순간의 값.
	int tempSum = 0;
	int index;
	while(answer == 0){
		index = 0;
		tempSum=0;
		for(int i=0; i<groupNum; i++){//내부검사
			for(int j=index; ; j++){
				if(index >= dvdNum){
					answer = average;
					break;
				}
				tempSum = tempSum + dvdTime[j];//한 그룹에서 얼마까지 들어가는지
				if(tempSum > average){//초과하면 탈출하는 조건
					tempSum = 0;
					break;
				}
				index++;
			}

		}
		//끝까지 다 들어갔다면 index가 진짜인덱스를 초과하게됨
		average++;
	}
	cout << answer;
	return 0;
}