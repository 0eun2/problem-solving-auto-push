#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

const int N = 4, LENGTH = 8;    // 톱니바퀴 개수, 길이
const int L = 6, R = 2; // 맞닿아 있는 톱니바퀴의 왼쪽, 오른쪽 인덱스

deque<int> wheel[N + 1];   // 톱니바퀴 (인덱스 1 ~ 4 사용)
vector<int> rotation(N + 1, 0); // 회전 방향 (시계: 1, 반시계: -1, 회전 X: 0)

void decideRotation(int num, int dir) {  // 톱니바퀴의 회전 상태 저장
    rotation[num] = dir;

    // 왼쪽 톱니바퀴 회전
    for (int i = num; i > 1; i--) {
        if (wheel[i - 1][R] != wheel[i][L]) { // 맞닿은 부분 극이 다르면
            rotation[i - 1] = -rotation[i]; // 반대방향으로 회전
        } else {    // 같으면
            rotation[i - 1] = 0;    // 회전 안 함
        }
    }

    // 오른쪽 톱니바퀴 회전
    for (int i = num; i < N; i++) {
        if (wheel[i][R] != wheel[i + 1][L]) {
            rotation[i + 1] = -rotation[i];
        } else {
            rotation[i + 1] = 0;
        }
    }

    return;
}

void rotate() {  // 회전 방향에 따라 회전
    for (int i = 1; i <= N; i++) {
        if (rotation[i] == 1) {   // 시계 방향
            wheel[i].push_front(wheel[i].back());
            wheel[i].pop_back();
        } else if (rotation[i] == -1) { // 반시계 방향
            wheel[i].push_back(wheel[i].front());
            wheel[i].pop_front();
        }
    }
    return;
}

int calcScore() {    // 톱니바퀴 점수의 합 출력
    int score = 0;  // 점수
    for (int i = 1; i <= N; i++) {
        score += pow(2, i - 1) * wheel[i][0];
    }
    return score;
}

int main() {
    // 입력
    string input;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        for (int j = 0; j < LENGTH; j++) {
            wheel[i].push_back(input[j] - '0');
        }
    }

    int k;  // 회전 횟수
    cin >> k;

    // 연산
    while (k--) {
        int num, dir;   // 회전 톱니바퀴의 번호, 방향
        cin >> num >> dir;
        decideRotation(num, dir);
        rotate();
    }

    //출력
    cout << calcScore();

    return 0;
}