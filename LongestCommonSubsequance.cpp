#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LCS(int i,int j,int l,int m,string &x, string &y)
{
    if( i==l || j == m ) {
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }


    int ans = 0;
    ans = max(ans,LCS(i+1,j,l,m,x,y));
    ans = max(ans,LCS(i,j+1,l,m,x,y));

    if(x[i] == y[j]){
        ans = max(ans,1 + LCS(i+1,j+1,l,m,x,y));
    }

    return dp[i][j] = ans;

}

int dp2[201][201][201];

int LCS2(int i, int j, int k, int l, int m, int n, string x, string y, string z )
{
    if(i==l || j==m || k==n){
        return 0;
    }

    if(dp2[i][j][k]!=-1){
        return dp2[i][j][k];
    }
    int ans = 0;

    ans = max(ans,LCS2(i+1,j,k,l,m,n,x,y,z));
    ans = max(ans,LCS2(i,j+1,k,l,m,n,x,y,z));
    ans = max(ans,LCS2(i,j,k+1,l,m,n,x,y,z));

    if(x[i]==y[j] && y[j]==z[k]){
        ans = max(ans,1+LCS2(i+1,j+1,k+1,l,m,n,x,y,z));
    }

    return dp2[i][j][k] = ans;

}

int main() {
    
    int l,n,m;
    string x,y,z;
    
    memset(dp, -1, sizeof dp);
    memset(dp2,-1, sizeof dp2);

    cin>>l>>m>>n;
    cin>>x>>y>>z;

    // cout<< LCS(0,0,l,m,x,y);
    // cout<<"\n";
    cout<< LCS2(0,0,0,l,m,n,x,y,z);

}
