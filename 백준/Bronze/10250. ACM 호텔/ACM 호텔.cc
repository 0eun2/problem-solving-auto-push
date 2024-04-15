#include <iostream>

using namespace std;

int main()
{
    int T, H, W, N;
    cin >> T;
    
    while(T--){
        cin >> H >> W >> N; //층, 방, 손님
        int ans = 1;
        while(N > H){ //01호부터 모든 층 채우기
            N -= H;
            ans++;
        } 
        cout << N * 100 + ans << '\n';
    }

    return 0;
}