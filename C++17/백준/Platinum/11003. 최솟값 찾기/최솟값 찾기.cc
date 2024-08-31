#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    deque<pair<int, int>> D;    //슬라이딩 윈도우 <i, A[i]>

    //입력
    cin >> N >> L;
    vector<int> A(N);
    for (int &i: A)
        cin >> i;

    //최솟값 찾기
    for (int i = 0; i < N; i++) {
        //범위를 벗어난 원소 삭제
        if(!D.empty() && D.front().first < i - L + 1)
            D.pop_front();
        //A[i]보다 큰 원소 삭제. D 오름차순 정렬 유지
        while(!D.empty() && D.back().second > A[i])
            D.pop_back();
        D.push_back(make_pair(i, A[i]));
        cout << D.front().second << ' ';
    }

    return 0;
}