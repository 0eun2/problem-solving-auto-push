#include<iostream>
#include<vector>

#define MAX 1000001

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    vector<long long> dp(MAX);

    //f(N)
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            dp[j] += i;
        }
    }

    //g(N)
    for (int i = 2; i < MAX; i++) {
        dp[i] += dp[i - 1];
    }

    cin >> T;

    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}