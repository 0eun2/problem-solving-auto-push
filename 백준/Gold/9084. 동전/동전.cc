#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> &coins) {
    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int coin: coins) {
        for (int j = coin; j <= m; j++)
            dp[j] += dp[j - coin];
    }

    return dp[m];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        vector<int> coins;

        // 입력
        cin >> n;
        coins.assign(n, 0);
        for (int &i: coins)
            cin >> i;
        cin >> m;

        // 출력
        cout << solution(n, m, coins) << '\n';
    }

    return 0;
}
