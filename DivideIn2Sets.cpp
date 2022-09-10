#include<bits/stdc++.h>
using namespace std;
// Instead of taking both A and B in states, we can derive B from A using B = TotalSum - A
// Therefore we don't need to track it in the state 
// We haev optimised the solution state wise and this is known as state space reduction


int dp[1005][1005];

int diviveIn2Sets(int n,int sum,int total,vector<int> &v)
{
	if(n == -1){
		if(sum == 0 || sum==total){
			return 0;
		}
		if((total - sum) % sum == 0){
			return 1;
		}
		return 0;
	}

	if(dp[n][sum]!=-1){ 
		return dp[n][sum];
	}
	int ways = 0;

	ways += diviveIn2Sets(n-1,sum,total,v) + diviveIn2Sets(n-1,sum+v[n],total,v);

	return dp[n][sum] = ways;
}

int diviveIn2SetsIterative(int n,int total,vector<int> &v)
{

	int dp[n+1][total+1];

	memset(dp,0,sizeof dp);

	for(int sum = 0; sum<=total ; sum++)
	{
		if( sum !=0 && sum!=total && (total - sum) % sum == 0){
			dp[n][sum] = 1;
		}else{
			dp[n][sum] = 0;
		}
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int sum = 0 ; sum<=total;sum++){

			dp[i][sum]  = dp[i+1][sum];
			if(sum + v[i] <= total){

				dp[i][sum] += dp[i+1][sum + v[i]];
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int sum = 0 ; sum<=total;sum++){
			cout<<dp[i][sum]<<' ';
		}
		cout<<'\n';
	}

	return dp[0][0];


}
void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);


	memset(dp,-1,sizeof dp);

	int total = 0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		total += v[i];
	}

	cout<<diviveIn2Sets(n-1,0,total,v)<<"\n";
	cout<<diviveIn2SetsIterative(n,total,v)<<"\n";
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