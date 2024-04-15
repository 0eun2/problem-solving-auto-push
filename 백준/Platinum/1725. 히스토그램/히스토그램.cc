#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, ans = 0;
    stack<int> stack;

    //입력
    cin >> N;
    vector<int> h(N + 2);   //높이
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    //연산
    stack.push(0);
    for (int i = 1; i <= N + 1; i++) {
        //현재 높이가 이전 높이보다 낮을 때
        while (!stack.empty() && h[stack.top()] > h[i]) {
            int height = h[stack.top()];
            stack.pop();
            int width = i - stack.top() - 1;
            ans = max(ans, height * width);
        }
        stack.push(i);
    }

    //출력
    cout << ans;

    return 0;
}