#include<iostream>
#include<vector>

using namespace std;

int N, S, ans = 0;
vector<int> v;

void dfs(int i, int sum){

    if(i == N) return;  //수열 탐색 완료
    if(sum + v[i] == S) ans++;  //더한 값이 S가 되는 경우

    dfs(i+1, sum);  //현재 값 안 더하고 넘어감
    dfs(i+1, sum+v[i]); //현재 값을 더하고 넘어감

}

int main() {

    cin >> N >> S;
    v.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}