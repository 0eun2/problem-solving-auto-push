#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), pre(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << pre[j] - pre[i - 1] << '\n';
    }

    return 0;
}