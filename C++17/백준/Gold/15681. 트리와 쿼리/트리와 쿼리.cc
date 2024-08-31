#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int cur, int prev, vector<vector<int>> &tree, vector<int> &dp) {
    for (int i = 0; i < tree[cur].size(); i++) {  //현재 정점의 자식 노드 탐색
        //현재 정점을 루트로 하는 서브트리(현재 정점 포함)의 정점이 아니면 탐색하지 않는다.
        if (tree[cur][i] == prev) {
            continue;
        }

        dfs(tree[cur][i], cur, tree, dp);
        dp[cur] += dp[tree[cur][i]];    //자식 노드의 dp값 더해주기
    }
    return;
}

//cur: 현재 노드, prev: 이전 노드
void solution(int cur, int prev, int q, vector<vector<int>> &tree, vector<int> &dp) {
    dfs(cur, prev, tree, dp);
    int input;
    while (q--) {
        cin >> input;
        cout << dp[input] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //입력
    int n, r, q, u, v;  //트리의 정점 수, 루트 번호, 쿼리 수, 간선의 정보
    cin >> n >> r >> q;

    //트리의 정점들의 연결관계를 저장
    vector<vector<int>> tree(n + 1, vector<int>(0));

    //해당 정점을 루트로 하는 서브트리에 속한 정점의 수를 저장
    //자신도 자신을 루트로 하는 서브트리에 포함됨. 초기값: 자신을 포함한 1
    vector<int> dp(n + 1, 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;

        //두 정점이 서로 연결되어 있음을 tree 벡터에 저장
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solution(r, 0, q, tree, dp);

    return 0;
}