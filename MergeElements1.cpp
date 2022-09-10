#include<bits/stdc++.h>
#define int long long
using namespace std;

// The element obtained from merging the element in range [l....R] will always be sum(v[L]....v[R]) % 100
// Irrespective of the way they are merged.
// Therefore for two parts [L.....mid......R], the totalSum can be calculated by iterating from L->r and 
// the cost will be rec(l,mid) + rec(mid+1,r) +  cost to merge these subarrays (sum % 100 * (total-sum % 100))

int dp[1005][1005];
int minCost(int l, int r, vector<int> &v)
{
    if(l==r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans = 1e9;
    int total = 0;

    for(int i=l;i<=r;i++){
        total+=v[i];
    }

    int sum = 0;

    for(int i=l;i<r;i++)
    {
        sum += v[i];
        ans = min(ans,minCost(l,i,v) + minCost(i+1,r,v) + ((sum %100) *((total-sum) % 100)));
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
    cout<<minCost(0,n-1,v)<<"\n";
    
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
}