#include<iostream>
#include<vector>

using namespace std;

string num; // 숫자판
int change_cnt; // 교환 횟수
int ans;

void dfs(int idx, int cnt) {
    // 종료 조건
    if (cnt == change_cnt) {  // 교환 횟수 모두 사용
        ans = max(ans, stoi(num));
        return;
    }

    for (int i = idx; i < num.length() - 1; i++) {
        for (int j = i + 1; j < num.length(); j++) {
            if (num[i] <= num[j]) {
                swap(num[i], num[j]);
                dfs(i, cnt + 1);
                swap(num[i], num[j]);
            }

            if (i == num.length() - 2 && j == num.length() - 1) {
                swap(num[i], num[j]);
                dfs(i, cnt + 1);
                swap(num[i], num[j]);
            }

        }

    }
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        // 입력
        cin >> num >> change_cnt;
        ans = 0;

        // 연산
        dfs(0, 0);

        // 출력
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}