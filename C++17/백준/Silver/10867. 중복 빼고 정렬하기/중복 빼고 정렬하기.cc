#include <iostream>
#include <set>

using namespace std;

int main() {

    int n;  // 수의 개수
    set<int> s;

    // 입력
    cin >> n;
    while (n--) {
        int input;
        cin >> input;
        s.insert(input);
    }

    // 출력
    for (int i: s) {
        cout << i << ' ';
    }

    return 0;
}