#include <bits/stdc++.h>
#define int long long
using namespace std;

/*

You are given N bricks in a line and M different coloured buckets of paint. 
You have to find the number of ways you can colour the brick wall such that there are exactly K positions out of the N bricks 
such that it has a different colour from the brick wall on its immediate left. 
(except the first brick, since there is no left brick). Print it modulo 10^9+7.

*/
const int mod = 1e9 + 7;
int dp[2005][2005];
int totalWays(int index,int n, int k, int m)
{
    // cout<<index<<" "<<k<<"\n";
    if(index==n)
    {
        if(k==0){
            // cout<<"Returned 1"<<'\n';
            return 1;
        }
        // cout<<"Returned 0"<<'\n';
        return 0;
    }

    if(dp[index][k]!=-1){
        return dp[index][k];
    }

    int ways = 0;

    // cout<<"Same as Previous"<<"\n";
    ways = ( ways  + (1*totalWays(index+1,n,k,m) % mod) % mod);

    // cout<<"Different as Previous"<<"\n";
    ways = ( ways + ((m-1)*totalWays(index+1,n,k-1,m) % mod) % mod);

    return dp[index][k] = ways;
}
signed main() {

    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        memset(dp, -1, sizeof dp);
        cout<< (m * totalWays(1,n,k,m) % mod )<<"\n";
    }
}