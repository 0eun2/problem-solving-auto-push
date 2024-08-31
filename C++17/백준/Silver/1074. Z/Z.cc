#include<iostream>

using namespace std;

int N, r, c, ans = 0;

void findZ(int x, int y, int size) {

    if (x == r && y == c)   //찾으려는 행과 열
    {
        cout << ans;
        return;
    }

    if (r >= x && c >= y && r < x + size && c < y + size) { //r, c가 현재 사분면에 존재하면
        int half_size = size / 2;
        findZ(x, y, half_size); //왼쪽 위 사분면
        findZ(x, y + half_size, half_size); //오른쪽 위
        findZ(x + half_size, y, half_size); //왼쪽 아래
        findZ(x + half_size, y + half_size, half_size); //오른쪽 아래
    } else {
        ans += size * size;
    }

}

int main() {

    cin >> N >> r >> c;

    findZ(0, 0, 1 << N);

    return 0;
}