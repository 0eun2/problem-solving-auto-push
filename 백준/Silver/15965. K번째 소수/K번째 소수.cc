#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll> p; // 소수 저장
bool check[9000005]; // 소수: false

void Eratosthenes(ll n) {
    for (ll i = 2; i <= n; i++)
        if (!check[i]) {
            p.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                check[j] = 1;
        }
}

int main() {

    Eratosthenes(9000000);
    ll k;
    cin >> k;
    cout << p[k - 1];

    return 0;
}