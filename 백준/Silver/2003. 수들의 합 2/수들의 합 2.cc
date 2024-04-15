#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N, M, sum = 0, ans = 0;

    //입력
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    //연산
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += v[j];

            if (sum > M)
                break;
            else if (sum == M) {
                ans++;
                break;
            }
        }
        sum = 0;
    }

    //출력
    cout << ans;

    return 0;
}