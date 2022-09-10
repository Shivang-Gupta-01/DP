#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool coinChange(int index, int total_left, int n,vector<int> &deno)
{
	if(total_left < 0){
		return false;
	}

	if(index == n){

		if(total_left == 0){
			return true;
		}
		return false;
	}

	if(dp[index][total_left]!=-1){
		return dp[index][total_left];
	}

	bool ans = false;

	ans  = coinChange(index+1,total_left,n,deno) | coinChange(index,total_left - deno[index],n,deno);

	return dp[index][total_left] = ans;

}

bool coinChange2(int n, int total_left,vector<int> &deno)
{
	if(total_left < 0){
		return false;
	}

	if(n == 0){

		if(total_left % deno[n] == 0){
			return true;
		}
		return false;
	}

	if(dp[n][total_left]!=-1){
		return dp[n][total_left];
	}

	bool ans = false;

	ans  = coinChange2(n-1,total_left,deno) | coinChange2(n,total_left - deno[n],deno);

	return dp[n][total_left] = ans;

}

int coinChangeIterative(int n, int sum, vector<int> &deno)
{

	int dp[n+1][sum+1];
	memset(dp, 0, sizeof dp);

	for(int i=n;i>=0;i--)
	{
		for(int s = 0; s<=sum; s++)
		{
			// Base Case
			if(i==n){
				if(s==0){
					dp[i][s] = 1;
				}else{
					dp[i][s] = 0;
				}
			}
			else{
				if(dp[i+1][s] == 1){
					dp[i][s] = 1;
				}
				if((s >= deno[i]) && (dp[i][s-deno[i]] == 1)){
					dp[i][s] = 1;
				}
			}
		}
	}

	for(int i=0; i<=n ;i++){
		for(int j = 0; j<=sum;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}

	return dp[0][sum];
}
void solve()
{

	int n,sum;
	cin>>n>>sum;

	memset(dp,-1,sizeof dp);
	vector<int> denominations(n);

	for(int i=0;i<n;i++)
	{
		cin>>denominations[i];
	}

	// cout<<coinChange(0,sum,n,denominations)<<" ";
	// cout<<coinChange2(n-1,sum,denominations)<<" ";
	cout<<coinChangeIterative(n,sum,denominations)<<"\n";
	
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
}