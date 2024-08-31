#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            v[i][j] += num;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}