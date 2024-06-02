#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;

    for (int i = 0; i < number.size() - k; i++) {
        char max_num = '0';
        for (int j = idx + 1; j <= k + i; j++) {
            if (max_num < number[j]) {
                max_num = number[j];
                idx = j;
            }
        }
        answer += max_num;
    }

    return answer;
}