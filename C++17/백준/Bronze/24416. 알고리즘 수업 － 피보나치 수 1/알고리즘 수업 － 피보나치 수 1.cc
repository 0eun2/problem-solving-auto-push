#include <iostream>
#include <vector>

using namespace std;

int cnt1, cnt2;

int fib(int n) {    // 재귀
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    } else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {  // dp
    vector<int> f(n + 1, 0);

    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt2++;
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main() {
    int n;
    cin >> n;
    cnt1 = 0, cnt2 = 0;

    fib(n);
    fibonacci(n);

    cout << cnt1 << ' ' << cnt2;

    return 0;
}