#include<iostream>
#include<vector>

using namespace std;

int calculate(int n, vector<vector<int>> v) {
    int ans = 0;
    for (int i = 0; i < n; i++) {   // 0 ~ n-1 행
        int num = abs(n / 2 - i);   // 현재 행과 중앙 행의 차이
        for (int j = num; j < n - num; j++) {
            ans += v[i][j];
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n, ans;  // 농장의 크기, 수익

        // 입력
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                v[i][j] = s[j] - '0';
            }
        }

        // 출력
        cout << '#' << test_case << ' ' << calculate(n, v) << '\n';
    }
    return 0;
}