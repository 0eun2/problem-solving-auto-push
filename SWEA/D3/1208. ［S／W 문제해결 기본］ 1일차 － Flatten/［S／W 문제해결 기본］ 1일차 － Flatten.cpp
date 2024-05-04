#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        int cnt;
        vector<int> v(100, 0);

        // 입력
        cin >> cnt;
        for (int &i: v) {
            cin >> i;
        }

        // 연산
        sort(v.begin(), v.end());

        while (cnt--) {
            v.front()++;
            v.back()--;

            sort(v.begin(), v.end());

            if (v.back() - v.front() <= 1) {
                break;
            }
        }

        // 출력
        cout << '#' << test_case << ' ' << v[v.size() - 1] - v[0] << '\n';
    }
    return 0;
}