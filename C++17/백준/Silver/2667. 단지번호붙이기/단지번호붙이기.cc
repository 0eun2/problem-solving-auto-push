#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<bool>> board;

//상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {  // 인덱스 오류
        return 0;
    }
    if (!board[x][y]) {    // 이미 방문한 곳
        return 0;
    }

    board[x][y] = false; // 방문 표기
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        cnt += dfs(x + dr[i], y + dc[i]);
    }

    return cnt;
}

int main() {
    string s;
    vector<int> ans;

    // 입력
    cin >> n;
    board.assign(n, vector<bool>(n, false));
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
                int cnt = dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());

    //출력
    cout << ans.size() << '\n';
    for (int &i: ans) {
        cout << i << '\n';
    }

    return 0;
}