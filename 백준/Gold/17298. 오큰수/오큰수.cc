#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack<int> S;
    vector<int> ans(N);
    for (int i = N - 1; i >= 0; i--) {
        while (!S.empty() && S.top() <= A[i]) S.pop();
        ans[i] = S.empty() ? -1 : S.top();
        S.push(A[i]);
    }

    for(int i : ans)
        cout << i << " ";

    return 0;
}