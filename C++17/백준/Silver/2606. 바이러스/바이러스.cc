#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<vector<bool> > adj;
vector<bool> visited;

void dfs(int com) {
    visited[com] = true;
    cnt++;

    for (int next = 1; next < n + 1; next++) {
        if (adj[com][next] && !visited[next])
            dfs(next);
    }
}

int main() {
    // 입력
    cnt = 0;
    cin >> n >> m;
    adj.assign(n + 1, vector<bool>(n + 1, false));
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        adj[r][c] = true;
        adj[c][r] = true;
    }

    // 연산
    dfs(1);

    // 출력
    cout << cnt - 1;
}
