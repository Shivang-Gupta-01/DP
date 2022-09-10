#include<bits/stdc++.h>
using namespace std;


// Method - 1
// The longest common suffix has the following optimal substructure property. 
// If last characters match, then we reduce both lengths by 1 
// L C S u f f ( X , Y , m , n ) = L C S u f f ( X , Y , m − 1 , n − 1 ) + 1 , if X [ m − 1 ] = Y [ n − 1 ] 
// If last characters do not match, then result is 0 , 
// i.e., L C S u f f ( X , Y , m , n ) = 0 , if ( X [ m − 1 ] ! = Y [ n − 1 ] ) 

// Now we consider suffixes of different substrings ending at different indexes. 
// The maximum length Longest Common Suffix is the longest common substring. 
// L C S u b S t r ( X , Y , m , n ) = M a x ( L C S u f f ( X , Y , i , j ) ) 
// where 1 <= i <= m and 1 <= j <= n

int dp[1005][1005];

int longestCommonSuffix(int i, int j, int m,int n, string x, string y)
{
    if(i == m || j == n){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;

    if(x[i]==y[j]){
        ans = max(ans,1 + longestCommonSuffix(i+1,j+1,m,n,x,y));
    }
    longestCommonSuffix(i+1,j,m,n,x,y);
    longestCommonSuffix(i,j+1,m,n,x,y);
    
    return dp[i][j] = ans;
}



// Method 2 - Recursion
// This method uses an additional state parameter of count
// if both characters match, count is updated to count+1
// Else it is updated to 0, since both don't match.

int dp2[105][105][105];

int longestCommonSubStr(int i,int j,int count, int m, int n, string x, string y)
{
    if(i==m || j==n){
        return count;
    }


    if(x[i]==y[j]){
        count = longestCommonSubStr(i+1,j+1,count+1,m,n,x,y);
    }

    count = max({count,longestCommonSubStr(i+1,j,0,m,n,x,y),longestCommonSubStr(i,j+1,0,m,n,x,y)});

    return count;
}


// Method 3
// Iterative DP

void solve()
{

    string x,y;
    cin>>x>>y;

    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);


    int m = x.length();
    int n = y.length();


    // Method 1
    int longestCommonSubString = 0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            longestCommonSubString = max(longestCommonSubString,longestCommonSuffix(i,j,m,n,x,y));
        }
    }
    cout<<longestCommonSubString<<" ";


    // Method 2

    cout<<longestCommonSubStr(0,0,0,m,n,x,y)<<"\n";


}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}