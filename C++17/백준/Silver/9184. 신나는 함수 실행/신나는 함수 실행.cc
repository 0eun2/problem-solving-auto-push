#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> dp;

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {   // 인덱스에 음수가 들어갈 수 없음
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {    // 인덱스에 21 이상이 들어갈 수 없음
        return w(20, 20, 20);
    } else if (dp[a][b][c]) { // 값이 존재하면 아래 재귀 생략
        return dp[a][b][c];
    } else if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c)
                      + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return dp[a][b][c];
}

int main() {
    int a, b, c;
    dp.assign(21, vector<vector<int>>(21, vector<int>(21, 0)));

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}