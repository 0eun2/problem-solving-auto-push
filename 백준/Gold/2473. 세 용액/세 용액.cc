#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1; //세 용액의 최댓값: 30억

ll min_diff = INF;

pair<ll, ll> liquid(vector<ll> &v, ll fixed, int left, int right) {
    pair<ll, ll> ans;   //세 용액 중 고정된 용액을 제외한 용액
    ans = make_pair(INF, INF);

    while (left < right) {
        ll mix = fixed + v[left] + v[right];
        if (mix == 0) {
            return make_pair(v[left], v[right]);
        }
        if (abs(mix) < min_diff) {
            min_diff = abs(mix);
            ans = make_pair(v[left], v[right]);
        }
        if (mix > 0) {  //값이 작아져야 함
            right--;
        } else {    //값이 커져야 함
            left++;
        }
    }
    return ans;
}

int main() {
    int N;  //용액의 수

    //입력
    cin >> N;
    vector<ll> v(N, 0);   //용액의 특성값
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    //연산
    sort(v.begin(), v.end());
    tuple<ll, ll, ll> ans;  //특성값이 0에 가장 가까운 용액을 만들어내는 경우
    for (int i = 0; i < N - 2; i++) {
        //v[i] 값은 고정 (하나의 용액을 반드시 사용한다고 가정)
        pair<ll, ll> p = liquid(v, v[i], i + 1, N - 1);
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(v[i], p.first, p.second);
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}