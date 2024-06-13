#include <iostream>
#include <map>
#include <vector>

using namespace std;

int passCar(int n, map<string, int> &enter, vector<string> &exit) {
    int ans = 0;

    for (int i = 0; i < n; i++) {   // 나온 차 탐색
        for (int j = i + 1; j < n; j++) {   // 뒤에 나온 차들과 비교
            // 들어갈 때 인덱스가 작은 차가 하나라도 있으면
            if(enter[exit[i]] > enter[exit[j]]){
                ans++;
                break;
            }
        }
    }

    return ans;
}

int main() {
    int n, ans = 0;  // n: 차의 대수
    string input;
    map<string, int> enter;   // 대근(입구)
    vector<string> exit;    // 영식(출구)

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {   // 들어간 차
        cin >> input;
        enter[input] = i;
    }
    for (int i = 0; i < n; i++) {   // 나간 차
        cin >> input;
        exit.push_back(input);
    }

    // 출력
    cout << passCar(n, enter, exit);

    return 0;
}