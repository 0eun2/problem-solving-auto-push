#include<iostream>

using namespace std;

int main() {
    int T;

    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        string origin;
        int ans = 0;
        char temp = '0';

        cin >> origin;

        for (char c: origin) {
            if (c == temp) continue;

            temp = c;
            ans++;
        }

        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}