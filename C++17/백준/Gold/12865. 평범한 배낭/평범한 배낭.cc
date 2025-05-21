#include <iostream>
#include <vector>

using namespace std;

struct info {
    int w, v;
};

int dp(int n, int k, vector<info> &item) {
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= item[i].w; j--)
            dp[j] = max(dp[j], dp[j - item[i].w] + item[i].v);
    }

    return dp[k];
}

int main() {
    int n, k;
    vector<info> item;

    // 입력
    cin >> n >> k;
    item.assign(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> item[i].w >> item[i].v;

    // 출력
    cout << dp(n, k, item);

    return 0;
}
