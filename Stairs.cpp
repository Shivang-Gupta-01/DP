#include<bits/stdc++.h>
using namespace std;

int dp[100100];

int countWays(int level, int n)
{

	// Prunning
	if(level>n){
		return 0;
	}

	// Base Case
	if(level==n){
		return 1;
	}

	if(dp[level]!=-1){
		return dp[level];
	}

	int ways = 0;
	// Choices
	for(int steps=1;steps<=3;steps++)
	{
		if(level + steps <= n){
			ways += countWays(level + steps, n);
		}
	}

	return dp[level] = ways;
}

int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof dp);
	cout<<countWays(0,n);
}