#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;  // n: 도감에 수록되어 있는 포켓몬의 개수, m: 맞춰야 하는 문제의 개수
    string input;
    map<string, int> pocket_name;   // 이름이 key
    map<int, string> pocket_num;    // 번호가 key

    // 입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { // 포켓몬 이름
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }

    while (m--) { // 문제
        cin >> input;
        if (isdigit(input[0])) {  // 숫자면
            cout << pocket_num[stoi(input)] << '\n';
        } else {
            cout << pocket_name[input] << '\n';
        }
    }

    return 0;
}