#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> &score) {
    int answer = 0;
    vector<int> dp(301, 0); //각 계단의 최댓값

    //n이 3미만일 경우 점화식이 해당되지 않기 때문에 초기화
    dp[1] = score[1];  //n = 1(1번째 계단은 1번째 계단 밟는게 최대)
    dp[2] = score[1] + score[2];    //n = 2(2번째 계단은 1번째 + 2번째 계단 밟는게 최대)

    for (int i = 3; i <= n; i++) { //3번째 계단부터 점화식 이용
        //1칸 전에서 온 경우(3칸 전 최댓값 + 2칸 이동한 1칸 전 값),
        //2칸 전에서 온 경우(2칸 전 최댓값 + 현재 계단 값)
        dp[i] = max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];
    }
    answer = dp[n]; //최대 점수가 저장되어있는 마지막 계단의 점수값
    return answer;
}

int main() {
    int n; //계단의 개수
    cin >> n;
    int answer;    //총 점수의 최댓값

    vector<int> score(301, 0); //계단의 개수(300이하)

    for (int i = 1; i <= n; i++) {  //1번째 인덱스부터 점수 입력
        cin >> score[i];
    }

    answer = solution(n, score);
    cout << answer;
}