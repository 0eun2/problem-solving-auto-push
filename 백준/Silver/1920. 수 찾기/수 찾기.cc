#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, m;
    vector<int> a, b;

    cin >> n;
    a.assign(n, 0);
    for (int &i: a)
        cin >> i;
    cin >> m;
    b.assign(m, 0);
    for (int &i: b)
        cin >> i;

    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
        cout << binary_search(a.begin(), a.end(), b[i]) << '\n';

    return 0;
}