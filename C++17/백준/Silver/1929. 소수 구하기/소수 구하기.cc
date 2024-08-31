#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

vector<bool> is_prime; //소수: true

void Eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if(!is_prime[i])
            continue;
        for (ll j = i * i; j <= n; j += i) {
            if(!is_prime[j])
                continue;
            is_prime[j] = false;
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    is_prime.assign(N + 1, true);
    Eratosthenes(N);

    for (int i = M; i <= N; i++) {
        if (is_prime[i])
            cout << i << '\n';
    }

    return 0;
}