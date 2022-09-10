#include<bits/stdc++.h>
using namespace std;


// The rod is represented as these coordinated -> 0,1,2,3,4,5,6,.....N

int dp[2005][2005];

int rodCutting(int l, int r, vector<int> &v)
{
	// A rod of length will has zero cost to cut
	if(l+1 == r)
	{
		return 0;
	}

	if(dp[l][r]!=-1){

		return dp[l][r];
	}
	int cost = INT_MAX;

	for(int p=l+1;p<=r-1;p++)
	{
		cost = min(cost, (v[r]-v[l]) + rodCutting(l,p,v) + rodCutting(p,r,v) );
	}

	return dp[l][r] = cost;

}

int main()
{
	int n;
	cin>>n;

	memset(dp, -1, sizeof dp);
	vector<int> v;


	for(int i=0;i<=n;i++)
	{
		v.push_back(i);	
	}

	cout<<rodCutting(0,n,v);
}