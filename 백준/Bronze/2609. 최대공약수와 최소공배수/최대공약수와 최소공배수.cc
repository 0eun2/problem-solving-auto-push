#include<iostream>

using namespace std;

int gcd(int a, int b) { //최대공약수
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int lcm(int a, int b) { //최소공배수
    return (a * b) / gcd(a, b);
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';

    return 0;
}