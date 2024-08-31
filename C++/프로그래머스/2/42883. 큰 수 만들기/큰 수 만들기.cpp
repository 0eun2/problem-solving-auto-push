#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;

    // number.length() - k 수 뽑기
    for (int i = 0; i < number.length() - k; i++) {
        char max_num = '0';
        for (int j = idx + 1; j <= k + i; j++) {    // 가장 큰 수 찾기
            if (max_num < number[j]) {
                max_num = number[j];
                idx = j;
            }
        }
        answer += max_num;
    }

    return answer;
}