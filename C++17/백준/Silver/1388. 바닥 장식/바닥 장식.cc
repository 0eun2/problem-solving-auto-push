#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> floor; //바닥 장식
vector<vector<bool>> visited; //방문
int N, M;   //세로, 가로

void dfs(int x, int y) {
    int nx, ny; //다음 위치
    visited[x][y] = true; //방문 표기
    if (floor[x][y] == '-') { //가로 무늬 탐색
        nx = x;
        ny = y + 1;
    } else {   //세로 무늬 탐색
        nx = x + 1;
        ny = y;
    }
    //1. 범위 체크 2. 무늬 체크 3. 방문 체크
    if (nx < N && ny < M && floor[x][y] == floor[nx][ny] && !visited[nx][ny]) {
        dfs(nx, ny);
    }
}

int solution() {
    int ans = 0;  //나무 판자 개수

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue; //방문 체크
            dfs(i, j);
            ans++;  //나무 판자 1개
        }
    }

    return ans;
}

int main() {

    cin >> N >> M;

    floor.assign(N, vector<char>(M, ' '));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> floor[i][j];
        }
    }

    cout << solution();

    return 0;
}