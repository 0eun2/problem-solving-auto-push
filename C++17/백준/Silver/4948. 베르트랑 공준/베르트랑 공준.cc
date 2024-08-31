#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int Eratosthenes(int n) {
    int cnt = 0;
    vector<bool> is_prime; //소수: true
    is_prime.assign(2 * n + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= 2 * n; i++) {
        if (!is_prime[i])
            continue;
        for (ll j = i * i; j <= 2 * n; j += i) {
            if (!is_prime[j])
                continue;
            is_prime[j] = false;
        }
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        if(is_prime[i])
            cnt++;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        cout << Eratosthenes(n) << '\n';
        cin >> n;
    }

    return 0;
}