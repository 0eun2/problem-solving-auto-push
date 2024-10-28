#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int num, int cnt) {
    // 종료 조건: M개의 수를 모두 선택함
    if (cnt == M) {
        for (int i: v)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; i++) {
        v.push_back(i);
        dfs(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;

    dfs(1, 0);

    return 0;
}