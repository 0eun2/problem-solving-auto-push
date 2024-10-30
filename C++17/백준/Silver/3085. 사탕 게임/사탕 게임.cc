#include <iostream>
#include <vector>

using namespace std;

/*
1. 행/열에서 인접한 두 칸을 골라 서로 사탕을 교환한다.
2. 연속하는 행/열의 최대 개수를 찾는다.
*/

int checkMax(int n, vector<vector<char>> &board) {
    int cnt, ret = 1;

    // 행에서 연속 개수
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[i][j] == board[i][j - 1]) cnt++;
            else cnt = 1;
            ret = max(cnt, ret);
        }
    }

    // 열에서 연속 개수
    for (int j = 0; j < n; j++) {
        cnt = 1;
        for (int i = 1; i < n; i++) {
            if (board[i][j] == board[i - 1][j]) cnt++;
            else cnt = 1;
            ret = max(cnt, ret);
        }
    }

    return ret;
}

int swapCandy(int n, vector<vector<char>> &board) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 행 탐색
            if (j < n - 1) {
                swap(board[i][j], board[i][j + 1]);
                ans = max(ans, checkMax(n, board));
                swap(board[i][j], board[i][j + 1]);
            }

            // 열 탐색
            if (i < n - 1) {
                swap(board[i][j], board[i + 1][j]);
                ans = max(ans, checkMax(n, board));
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    return ans;
}

int main() {
    int n;

    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << swapCandy(n, board);

    return 0;
}