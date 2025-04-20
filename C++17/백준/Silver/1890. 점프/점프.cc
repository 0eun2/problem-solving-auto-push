#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll coutRoute(int n, vector<vector<ll>> &v)
{
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!v[i][j])
                continue;
            int right = j + v[i][j];
            int down = i + v[i][j];
            if (right < n)
                dp[i][j + v[i][j]] += dp[i][j];
            if (down < n)
                dp[i + v[i][j]][j] += dp[i][j];
        }
    }

    return dp[n - 1][n - 1];
}

int main()
{
    int n;
    vector<vector<ll>> v;
    
    cin >> n;
    v.assign(n, vector<ll>(n, 0));
    
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
            
    cout << coutRoute(n, v);

    return 0;
}