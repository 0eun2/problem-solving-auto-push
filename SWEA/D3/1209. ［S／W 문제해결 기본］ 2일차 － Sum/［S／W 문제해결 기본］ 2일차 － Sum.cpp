#include<iostream>
#include<vector>

using namespace std;

const int N = 100;

int calculate(vector<vector<int>> &v) {
    int ans = 0, sum = 0;

    // 행
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += v[i][j];
        }
        ans = max(sum, ans);
    }

    // 열
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += v[j][i];
        }
        ans = max(sum, ans);
    }

    // 우하향 대각선
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i][i];
    }
    ans = max(sum, ans);

    // 좌하향 대각선
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i][N - 1 - i];
    }
    ans = max(sum, ans);

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