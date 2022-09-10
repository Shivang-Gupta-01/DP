#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
int dp[1005][1005];
bool grid[1005][1005];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                dp[i][j] = 0;
            }
        }
        if(grid[0][0] || grid[n-1][m-1]) {
            cout << 0 << "\n";
            continue;
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j]) {
                    continue;
                }
                if(i) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                }
                if(j) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                }
            }
        }
        cout << dp[n-1][m-1] << "\n";
    }
    return 0;
}