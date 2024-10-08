#include<iostream>

using namespace std;

int factorial(int n){
    if(n <= 1)
        return 1;
    else
        return n * factorial(n-1);
}

int main() {

    int N, K;
    cin >> N >> K;

    cout << factorial(N) / (factorial(K) * factorial(N - K));

    return 0;
}

//nCk = n! / (k!(n-k)!)