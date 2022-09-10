#include<bits/stdc++.h>
#define int long long
using namespace std; 
string T = "hard";

int dp[100005][5];
int minCost(int index,int prefix,int n,string &s, vector<int> &cost)
{
    if(prefix==4){
        return 1e18;
    }
    
    if(index == n){
        return 0;
    }

    if(dp[index][prefix]!=-1){
        return dp[index][prefix];
    }
    
    int ans = 1e18;
    
    if(T[prefix] == s[index]){
        ans = min({ans, minCost(index+1,prefix+1,n,s,cost), cost[index] + minCost(index+1,prefix,n,s,cost)});
    }else{
        ans = min(ans, minCost(index+1,prefix,n,s,cost));
    }
    return dp[index][prefix] = ans;
}
void solve()
{
    memset(dp,-1,sizeof dp);
	int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<minCost(0,0,n,s,cost)<<"\n";
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