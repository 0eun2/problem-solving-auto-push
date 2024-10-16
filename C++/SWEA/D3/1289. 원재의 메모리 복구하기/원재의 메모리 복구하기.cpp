#include<iostream>

using namespace std;

int main() {
    int T;

    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        string origin, init = "";
        int cnt = 0;
        
        cin >> origin;

        for (int i = 0; i < origin.length(); i++) {
            init += '0';
        }

        for (int i = 0; i < origin.length(); i++) {
            if (origin[i] == init[i]) continue;

            for (int j = i; j < origin.length(); j++) {
                init[j] = origin[i];
            }

            cnt++;
        }

        cout << '#' << test_case << ' ' << cnt << '\n';
    }

    return 0;
}