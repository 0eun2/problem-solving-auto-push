#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
vector<vector<int>> board;
vector<int> ans;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    // 인덱스 에러 방지
    // 종료 조건: 집이 없거나 이미 방문한 곳
    if (r < 0 || r >= n || c < 0 || c >= n || !board[r][c]) {
        return;
    }

    cnt++;
    board[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        dfs(r + dr[i], c + dc[i]);
    }
}

int main() {
    string s;

    //입력
    cin >> n;
    board.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    //출력
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i: ans)
        cout << i << '\n';

    return 0;
}