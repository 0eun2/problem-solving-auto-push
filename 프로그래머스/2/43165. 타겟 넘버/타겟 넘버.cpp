#include <iostream>
#include <vector>

using namespace std;

int answer;

void dfs(int idx, int sum, int target, vector<int> &numbers) {
    if (idx == numbers.size()) {   // 종료 조건: 모든 수 탐색 완료
        if (sum == target) {    // target과 같으면 경우의 수 + 1
            answer++;
        }
        return;
    }

    dfs(idx + 1, sum + numbers[idx], target, numbers);  // + 선택
    dfs(idx + 1, sum - numbers[idx], target, numbers);  // - 선택
}

int solution(vector<int> numbers, int target) {
    answer = 0;

    dfs(0, 0, target, numbers);

    return answer;
}