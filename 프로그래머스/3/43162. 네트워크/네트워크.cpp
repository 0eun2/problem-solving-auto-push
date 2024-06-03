#include <iostream>
#include <vector>

using namespace std;

vector<bool> isVisited;

void dfs(int cur, int n, vector<vector<int>> computers) {
    isVisited[cur] = true;  // 방문 표기

    for (int i = 0; i < n; i++) {
        // 방문하지 않은 컴퓨터이고, 현재 컴퓨터와 연결되어 있다면
        if (!isVisited[i] && computers[cur][i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    isVisited.assign(n, false);

    for (int i = 0; i < n; i++) { // 컴퓨터 방문
        if (!isVisited[i]) { // 아직 방문하지 않은 컴퓨터
            dfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}