#include<iostream>

using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;

    for (int i = 1; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            if (i * i + N == j * j)
                ans++;
        }
    }

    cout << ans;

    return 0;
}