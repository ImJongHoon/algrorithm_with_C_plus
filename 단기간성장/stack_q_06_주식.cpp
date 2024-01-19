#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct info {
    int price;
    int sec;
};

//한 주식이 초단위. 바로 다음 index에 값이 떨어져도 1초. 즉 자기 자신을 1초로 셈.
vector<int> solution(vector<int> prices) {
    vector<int> answer;

    //어느 시점에 들어갔는지도 함께 저장해둬야 끝까지 빠지지 않은 애들의 시간을 계산해주기 쉽다.
    stack<info> s;

    answer = vector<int>(prices.size(), -1);

    for (int i = 0; i < prices.size(); i++) {
        if (s.empty()) {
            s.push( {prices[i], i} );
        }
        else {
            //stack이 다 비거나, 가격이 작거나 같을 때까지 pop
            while (!s.empty() && s.top().price > prices[i]) {
                //주식 가격이 오른 sec = 현재 시점(i) - stack에 저장되어 있는 시점
                int temp = i - s.top().sec;
                answer[s.top().sec] = temp;

                s.pop();
            }
            s.push({ prices[i], i });
        }
    }

    int temp;

    while (!s.empty()) {
        temp = prices.size() - 1 - s.top().sec;
        answer[s.top().sec] = temp;
        s.pop();
    }

    return answer;
}

int main() {
    vector<int> prices = { 1, 2, 3, 2, 3 };
    
    solution(prices);

    return 0;
}