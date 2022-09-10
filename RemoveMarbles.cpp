#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[105][105][105];

int maxCost(int l, int r, int trailingMarble, vector<int> &v)
{
    // Base Case
    if(l > r){
        return 0;
    }

    if(dp[l][r][trailingMarble]!=-1){
        return dp[l][r][trailingMarble];
    }
    // Prunning to find simmilar colored marbles
    while( l < r && v[l] == v[l+1]){
        l++;
        trailingMarble++;
    }

    // By this time l has increased to the spot where 
    int ans = maxCost(l+1,r,0,v) + (trailingMarble+1)*(trailingMarble+1);

    for(int i=l+1;i<=r;i++)
    {
        if(v[l]==v[i])
        {
            ans = max(ans, maxCost(l+1,i-1,0,v) + maxCost(i,r,trailingMarble+1,v));
        }
    }

    return dp[l][r][trailingMarble] = ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);

    memset(dp, -1, sizeof dp);
    
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<maxCost(0,n-1,0,v);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
}}