#include<iostream>

using namespace std;
typedef long long ll;

ll fpow(int A, int B, int C) {
    if (B == 0) return 1;
    ll k = fpow(A, B / 2, C);
    k = k * k % C;
    if (B % 2) k = k * A % C;
    return k;
}

int main() {

    int A, B, C;
    ll ans;
    cin >> A >> B >> C;

    cout << fpow(A, B, C);

    return 0;
}