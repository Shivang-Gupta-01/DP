#include<bits/stdc++.h>
using namespace std;

int kadanes(int n, vector<int> &v)
{
	int res = -1e9;
	int sum = 0;

	for(int i=0;i<n;i++)
	{
		sum+= v[i];

		if(res < sum){
			res = sum;
		}
		if(sum<0){
			sum = 0;
		}
	}

	return res;
}
int dp[100005];
int done[100005];

int maximumSum(int index,vector<int> &v)
{
	if(index==0){
		return v[0];
	}

	if(done[index]){
		return dp[index];
	}
	int ans = max({ans,v[index], v[index] + maximumSum(index-1,v)});
	done[index] = 1;
	return dp[index] = ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);

	memset(dp,-1,sizeof dp);
	memset(done,0,sizeof dp);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	cout<<kadanes(n,v)<<"\n";

	int res = -1e9;
	for(int i=0;i<n;i++){
		cout<<maximumSum(i,v)<<' ';
		res = max(res,maximumSum(i,v));
	}
	cout<<res;
}

