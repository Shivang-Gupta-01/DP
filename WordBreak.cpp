#include<bits/stdc++.h>
using namespace std;
int dp[100005];
bool rec(int index, int n, string &s, unordered_map<string,int> &mp){
    
    cout<<index<<"\n";
    if(index==n){
        return true;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int ans = 0;
    
    for(int i=index;i<n;i++){
        string substring = s.substr(index,i-index+1);
        cout<<substring<<"\n";
        if(mp.find(substring)!=mp.end()){
            if(rec(i+1,n,s,mp)){
                ans = 1;
            }
        }
    }
    
    return dp[index] = ans;
}


void solve()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    string s;
    unordered_map<string,int> mp;
    cin>>s;
    string temp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        mp[temp] = 1;
    }
    
    cout<<rec(0,n,s,mp)<<'\n';
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