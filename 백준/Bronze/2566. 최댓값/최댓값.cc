#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<vector<int>> v(9, vector<int>(9));
    int max = 0, n = 1, m = 1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num;
            cin >> num;
            v[i][j] = num;
            if (num > max) {
                max = num;
                n = i + 1;
                m = j + 1;
            }
        }
    }

    cout << max << '\n' << n << ' ' << m;

    return 0;
}