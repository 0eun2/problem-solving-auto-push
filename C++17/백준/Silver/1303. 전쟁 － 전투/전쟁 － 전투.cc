#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, m, cnt;
char color;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<int> w, b;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c)
{
    // 인덱스
    // 종료 조건: 같은 병사가 아니거나 이미 방문한 곳
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != color || visited[r][c])
        return;
    
    cnt++;
    visited[r][c] = true;
    
    for (int i = 0; i < 4; i++)
        dfs(r + dr[i], c + dc[i]);
}

int main()
{
    // 입력
    cin >> n >> m;
    board.assign(m, vector<char>(n));
    visited.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                color = board[i][j];
                cnt = 0;
                dfs(i, j);
                if (color == 'W')
                    w.push_back(cnt * cnt);
                else
                    b.push_back(cnt * cnt);
            }
        }
    }
    
    // 출력
    cout << accumulate(w.begin(), w.end(), 0) << ' ' << accumulate(b.begin(), b.end(), 0);

    return 0;
}