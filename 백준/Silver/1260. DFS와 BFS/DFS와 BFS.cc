#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> adj;    // 인접 행렬
vector<bool> visited_dfs; // DFS 방문 처리

void dfs(int n, int curr) {
    if (visited_dfs[curr])
        return;

    visited_dfs[curr] = true;
    cout << curr << ' ';
    for (int next = 1; next <= n; next++) {
        if (adj[curr][next]) {
            dfs(n, next);
        }
    }
}

void bfs(int n, int v) {
    vector<bool> visited(n + 1, false);   // 방문 처리
    queue<int> q;

    q.push(v);
    visited[v] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        cout << curr << ' ';
        q.pop();
        
        for (int next = 1; next <= n; next++) {
            if (!adj[curr][next] || visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
}

int main() {
    int n, m, v, a, b;
    cin >> n >> m >> v;

    adj.assign(n + 1, vector<bool>(n + 1, false));
    visited_dfs.assign(n + 1, false);

    while (m--) {
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    dfs(n, v);
    cout << '\n';
    bfs(n, v);

    return 0;
}