#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

ll fpow(ll x) {
    if (x == 0) return 1;
    ll ret = fpow(x / 2);
    ret = ret * ret % M;
    if (x % 2) ret = ret * 2 % M;
    return ret;
}

int main() {

    ll N, C, K, ans = 0;
    cin >> N;

    while (N--) {
        cin >> C >> K;
        ans = (ans + ((C * K) % M) * fpow(K - 1)) % M;
    }

    cout << ans;

    return 0;
}