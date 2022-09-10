#include<bits/stdc++.h>
using namespace std;


int dp[1005][1005];

int maxLength(int row, int col, vector<vector<int>> &v)
{
	if(row <0 || col < 0){
		return 0;
	}

	if(row == 0 && col == 0){
		return v[0][0];
	}

	if(dp[row][col]!=-1){
		return dp[row][col];
	}

	int len = (v[row][col]==1) + min({maxLength(row-1,col-1,v),maxLength(row,col-1,v),maxLength(row-1,col,v)});

	return dp[row][col] = len;

}

int maxLengthIterative(int n,int m, vector<vector<int>> &v)
{
	int dp[n][m];

	memset(dp, 0, sizeof dp);

	int res = -1e9;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){

				if(i==0 || j==0){
					dp[i][j] = v[i][j];
				}
				else{
					if( v[i][j] == 1){

						int len = 1e9;
						if(i > 0){
							len = min(len,dp[i-1][j]);
						}
						if(j > 0){
							len = min(len,dp[i][j-1]);
						}
						if(i >0 && j >0)
						{
							len = min(len,dp[i-1][j-1]);
						}
						dp[i][j] = 1 + len;
					}	
				
				}
			cout<<dp[i][j]<<" ";
			res = max(res,dp[i][j]);
		}
		cout<<'\n';
	}

	return res*res;

}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));

	memset(dp, -1, sizeof dp);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
		}
	}

	int res = -1e9;

	for(int i=0;i<n;i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(v[i][j])
			{
				res = max(res,maxLength(i,j,v));
			}
		}
	}

	cout<< res*res <<"\n";

	cout<<maxLengthIterative(n,m,v);



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