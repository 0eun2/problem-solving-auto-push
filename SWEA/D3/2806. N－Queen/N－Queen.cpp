#include<iostream>
#include<vector>

using namespace std;

int n, ans;
vector<int> row;

bool check(int col) {
    for (int i = 0; i < col; i++) { // 현재 퀸이 놓인 모든 열
        // 1. 같은 행에 퀸이 있는지
        // 2. 같은 대각선에 퀸이 있는지 (행 차이 = 열 차이)
        if (row[col] == row[i] || col - i == abs(row[col] - row[i])) {
            return false;
        }
    }
    return true;
}

void backtracking(int col_cnt) {
    if (col_cnt == n) {   // 종료 조건: 모든 열에 퀸 배치 완료
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {   //모든 행
        row[col_cnt] = i;   // [i, col_cnt]에 퀸 배치
        if (check(col_cnt)) {   //배치할 수 있는지
            backtracking(col_cnt + 1);
        }
    }
}

int main() {
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        // 입력 & 초기화
        cin >> n;
        ans = 0;
        row.assign(n, 0);

        // 연산
        backtracking(0);

        // 출력
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}