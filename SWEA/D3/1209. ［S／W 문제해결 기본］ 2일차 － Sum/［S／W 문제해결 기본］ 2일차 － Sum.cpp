#include<iostream>
#include<vector>

using namespace std;

const int N = 100;

int calculate(vector<vector<int>> &v) {
    int ans = 0, row_sum = 0, col_sum = 0, r_sum = 0, l_sum = 0;    // 행, 열, 우하향, 좌하향 대각선

    for (int i = 0; i < N; i++) {
        r_sum += v[i][i];   // 우하향 대각선
        l_sum += v[i][N - 1 - i];   // 좌하향 대각선
        for (int j = 0; j < N; j++) {
            row_sum += v[i][j]; // 행
            col_sum += v[j][i]; // 열
        }
        ans = max(ans, max(row_sum, col_sum));
        row_sum = 0;
        col_sum = 0;
    }
    ans = max(ans, max(l_sum, r_sum));
    return ans;
}

int main() {
    int T = 10;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int num;
        vector<vector<int>> v(N, vector<int>(N, 0));

        // 입력
        cin >> num;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> v[i][j];
            }
        }

        // 출력
        cout << '#' << test_case << ' ' << calculate(v) << '\n';
    }

    return 0;
}