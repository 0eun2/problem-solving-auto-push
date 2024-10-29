#include<iostream>

using namespace std;

int main() {

    long long s;
    int n = 1;
    cin >> s;

    while (s >= n) {
        s -= n++;
    }

    cout << n - 1;

    return 0;
}