#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[1005][1005];
int destroyGemStones(int l, int r, vector<int> &v)
{
    if(l > r){
        return 0;
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    
    int ans = 1e9;
    
    ans = min(ans,1+destroyGemStones(l+1,r,v));


        if(v[l]==v[l+1]){
            ans = min(ans,1 + destroyGemStones(l+2,r,v));
        }

    
    for(int i=l+2;i<=r;i++)
    {
        if(v[l] == v[i]){
            ans = min(ans,destroyGemStones(l+1,i-1,v) + destroyGemStones(i+1,r,v));
        }
    }

    return dp[l][r] = ans;
}
void solve()
{
    int n;
    cin>>n;
    
    memset(dp,-1,sizeof dp);
    
    vector<int> v(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<destroyGemStones(0,n-1,v)<<"\n";
    
}

signed main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}