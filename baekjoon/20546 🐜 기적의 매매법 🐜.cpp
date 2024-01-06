#include <iostream>

using namespace std;

int calBnp(int* stock, int money) {
    int result;
    int stock_num = 0;
    int can_buy_num;
    int remain_money;

    //초기값 대입
    remain_money = money;

    for (int i = 0; i < 14; i++) {
        can_buy_num = remain_money / stock[i];

        stock_num = stock_num + can_buy_num;//가진 주식개수 늘리고
        remain_money = remain_money - (stock[i] * can_buy_num);//돈은 줄이고
    }

    result = remain_money + (stock_num * stock[13]);

    return result;
}

int calTiming(int* stock, int money) {
    int result;
    int up_count = 0;
    int down_count = 0;
    int remain_money = money;
    int stock_num = 0;//주식 보유 갯수
    int can_buy_stock = 0;

    for (int i = 1; i < 14; i++) {//13번
        if (stock[i] > stock[i - 1]) {//올랐으면
            up_count++;
            down_count = 0;
        }
        else if (stock[i] < stock[i - 1]) {//떨어졌으면
            down_count++;
            up_count = 0;
        }
        else if (stock[i] == stock[i - 1]) {
            up_count = 0;
            down_count = 0;
        }

        if (up_count >= 3) {//전량매도
            remain_money = remain_money + (stock_num * stock[i]);
            stock_num = 0;
        }
        else if (down_count >= 3) {//전량매수
            can_buy_stock = remain_money / stock[i];
            stock_num = stock_num + can_buy_stock;
            remain_money = remain_money - (can_buy_stock * stock[i]);
        }
    }

    result = remain_money + (stock_num * stock[13]);

    return result;
}

int main() {
    int money;
    int stock[14];
    int bnp;
    int timing;

    cin >> money;

    for (int i = 0; i < 14; i++) {
        cin >> stock[i];
    }

    bnp = calBnp(stock, money);
    timing = calTiming(stock, money);

    if (bnp > timing) {
        cout << "BNP";
    }
    else if (bnp < timing) {
        cout << "TIMING";
    }
    else if (bnp == timing) {
        cout << "SAMESAME";
    }

    return 0;
}