#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> v;
vector<bool> visited;

void dfs(int cur) {
    // 종료 조건: M개의 수를 모두 선택함
    if (cur == M) {
        for (int i: v)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);

            dfs(cur + 1);

            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    visited.assign(N + 1, false);

    dfs(0);

    return 0;
}