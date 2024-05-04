#include<iostream>
#include<vector>

using namespace std;

int main() {
    int T = 10;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n, ans = 0;

        // 입력
        cin >> n;

        vector<int> building(n, 0);
        for (int &i: building)
            cin >> i;

        // 연산
        for (int i = 2; i < n - 2; i++) {
            int max_building = max(max(building[i + 1], building[i + 2]), max(building[i - 1], building[i - 2]));
            if (building[i] > max_building)
                ans += building[i] - max_building;
        }

        // 출력
        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}