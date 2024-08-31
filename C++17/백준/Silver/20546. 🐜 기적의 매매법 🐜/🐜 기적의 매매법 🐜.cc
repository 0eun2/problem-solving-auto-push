#include <iostream>
#include <vector>

using namespace std;

const int DAY = 14;

int bnp(int cash, vector<int> &price) {
    int stock = 0;

    for (int i = 0; i < DAY; i++) {
        while (cash - price[i] >= 0) {
            cash -= price[i];
            stock++;
        }
    }

    return stock * price[DAY - 1] + cash;
}

int timing(int cash, vector<int> &price) {
    int stock = 0, up = 0, down = 0;

    for (int i = 1; i < DAY; i++) {
        // 가격 상승, 하락 체크
        if (price[i - 1] < price[i]) {  // 가격 상승
            up++;
            down = 0;
        } else if (price[i - 1] > price[i]) {   // 가격 하락
            down++;
            up = 0;
        } else {    // 주가 동일
            up = 0;
            down = 0;
        }

        // 매도, 매수
        if (up == 3) { // 3일 연속 가격 상승
            while (stock) {  // 전량 매도
                cash += price[i];
                stock--;
            }
            up = 0;
        } else if (down == 3) {  // 3일 연속 가격 하락
            while (cash - price[i] >= 0) {  // 전량 매수
                cash -= price[i];
                stock++;
            }
            down = 0;
        }
    }

    return stock * price[DAY - 1] + cash;
}

int main() {
    int cash, bnp_result, timing_result;
    vector<int> price(DAY, 0);

    // 입력
    cin >> cash;
    for (int &i: price) {
        cin >> i;
    }

    // 연산
    bnp_result = bnp(cash, price);
    timing_result = timing(cash, price);

    // 출력
    if (bnp_result > timing_result)
        cout << "BNP";
    else if (bnp_result < timing_result)
        cout << "TIMING";
    else
        cout << "SAMESAME";

    return 0;
}
