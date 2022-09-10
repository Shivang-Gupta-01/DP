#include<bits/stdc++.h>
using namespace std;

int dp[2005][2005];

// Here we would need to keep another boolean dp to check if the state has actually been computed or not.
// Since it is posibble that actually the value of dp[n][m] = -1 (Due to -ve weights)

bool done[2005][2005];

int maximumPathSum(int n, int m,vector<vector<int>> &v ){

	if( n < 0  || m < 0){
		return -1e9;
	}

	if(n==0 && m==0){
		return v[0][0];
	}


	if( done[n][m] ){
		return dp[n][m];
	}

	int ans = -1e9;
	if(n!=0){
		ans = max(ans,maximumPathSum(n-1,m,v) + v[n][m] );
	}

	if(m!=0){
		ans = max(ans,maximumPathSum(n,m-1,v) + v[n][m]) ;
	}

	done[n][m] = true;
	return dp[n][m] = ans;
}
int main()
{
	int n,m;
	cin>>n>>m;

	memset(dp, -1, sizeof dp);

	vector<vector<int>> v(n,vector<int>(m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
			done[i][j] = 0;
		}
	}

	cout<<maximumPathSum(n-1,m-1,v);
}