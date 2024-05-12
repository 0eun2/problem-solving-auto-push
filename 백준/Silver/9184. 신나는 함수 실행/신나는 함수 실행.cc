#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> dp;

int w(int a, int b, int c) {
    int a_idx = a + 50, b_idx = b + 50, c_idx = c + 50;
    if (dp[a_idx][b_idx][c_idx]) // 값이 존재하면
        return dp[a_idx][b_idx][c_idx];
    else if (a <= 0 || b <= 0 || c <= 0) {
        dp[a_idx][b_idx][c_idx] = 1;
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        a_idx = 70, b_idx = 70, c_idx = 70;
        dp[a_idx][b_idx][c_idx] = w(20, 20, 20);
    } else if (a < b && b < c) {
        dp[a_idx][b_idx][c_idx] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        dp[a_idx][b_idx][c_idx] = w(a - 1, b, c) + w(a - 1, b - 1, c)
                                  + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return dp[a_idx][b_idx][c_idx];
}

int main() {
    int a, b, c;
    dp.assign(101, vector<vector<int>>(101, vector<int>(101, 0)));

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}