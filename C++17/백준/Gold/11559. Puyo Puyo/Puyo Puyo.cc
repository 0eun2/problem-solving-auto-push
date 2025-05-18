#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX_ROW = 12;
const int MAX_COL = 6;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void update_field(vector<vector<char>> &field) {
    for (int i = 0; i < MAX_COL; i++) {
        vector<char> puyo;
        for (int j = 0; j < MAX_ROW; j++) {
            if (field[j][i] == '.')
                continue;
            puyo.push_back(field[j][i]);
        }
        for (int j = MAX_ROW - 1; j >= 0; j--) {
            if (puyo.empty()) {
                field[j][i] = '.';
            } else {
                field[j][i] = puyo.back();
                puyo.pop_back();
            }
        }
    }
}

bool bfs(int r, int c, vector<vector<char>> &field) {
    queue<pii> q;
    vector<pii> exploded;
    vector<vector<bool> > visited(MAX_ROW, vector<bool>(MAX_COL, false));
    int cnt = 1;
    char color = field[r][c];

    q.push({r, c});
    exploded.push_back({r, c});
    visited[r][c] = true;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= MAX_ROW || nc < 0 || nc >= MAX_COL
                || field[nr][nc] != color || visited[nr][nc])
                continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
            exploded.push_back({nr, nc});
            cnt++;
        }
    }

    if (cnt < 4)
        return false;

    for (auto i: exploded)
        field[i.first][i.second] = '.';
    return true;
}

int solution(vector<vector<char>> &field) {
    int ans = 0;

    while (true) {
        bool flag = false;
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                if (field[i][j] == '.')
                    continue;
                if (bfs(i, j, field))
                    flag = true;
            }
        }
        if (!flag)
            break;
        update_field(field);
        ans++;
    }
    return ans;
}

int main() {
    vector<vector<char> > field(MAX_ROW, vector<char>(MAX_COL, '.'));

    // 입력
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            cin >> field[i][j];
        }
    }

    // 출력
    cout << solution(field);

    return 0;
}
