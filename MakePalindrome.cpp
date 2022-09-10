#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int minMoves(int l,int r, string &s)
{
    if(l>=r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans = 1e9;
    
    if(s[l]==s[r]){
        ans = min(ans,minMoves(l+1,r-1,s));
    }else{
        ans = min({ans,1 + minMoves(l,r-1,s),1 + minMoves(l+1,r,s)});
    }
    
    return dp[l][r] = ans;
    
}

void solve()
{
    string s;
    cin>>s;
    int n = s.length();
    
    memset(dp,-1,sizeof dp);
    cout<<minMoves(0,n-1,s)<<"\n";
    
    
    
}
int main()
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