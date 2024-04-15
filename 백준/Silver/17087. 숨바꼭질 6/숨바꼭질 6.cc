#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) { //최대공약수
    return b ? gcd(b, a % b) : a;
}

int main() {
    int N, S, D = 0;

    //입력
    cin >> N >> S;
    vector<int> A(N);
    for (int &i: A) {
        cin >> i;
    }

    //연산
    for (int &i: A) { //수빈이와의 거리 차이
        i = abs(S - i);
    }

    D = A[0];
    for (int i = 0; i < N; i++) {
        D = gcd(D, A[i]);
    }

    //출력
    cout << D;

    return 0;
}