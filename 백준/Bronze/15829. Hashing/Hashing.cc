#include<iostream>

#define M 1234567891
#define r 31

using namespace std;

int main() {

    int L;
    long long ans = 0, R = 1;
    string s;
    cin >> L >> s;

    for (int i = 0; i < L; i++) {
        ans += (s[i] - 'a' + 1) * R % M;
        R = (R * 31) % M;
    }

    cout << ans % M;

    return 0;
}

/*
    (a + b) mod n = {(a mod n) + (b mod n)} mod n
    (a * b) mod n = {(a mod n) * (b mod n)} mod n
 */