#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 9;
const ll MAX = 1e6;

vector<ll> numberOfAllCases() {
    vector<ll> dp(MAX + 1, 0);

    //초기 조건
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    //점화식
    for (int i = 3; i <= MAX; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    return dp;
}

int main() {
    int t, n;
    vector<ll> dp = numberOfAllCases();
    cin >> t;

    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}