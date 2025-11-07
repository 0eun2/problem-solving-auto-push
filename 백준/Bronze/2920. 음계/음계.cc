#include<iostream>
#include<vector>

using namespace std;

int main() {

    int asc = 0, des = 0;
    vector<int> v(8);

    for (int i = 0; i < 8; i++) {
        cin >> v[i];
        if (v[i] == i + 1) {
            asc++;
        } else if (v[i] == 8 - i) {
            des++;
        }
    }

    if (asc == 8) {
        cout << "ascending";
    } else if (des == 8) {
        cout << "descending";
    } else {
        cout << "mixed";
    }

    return 0;
}