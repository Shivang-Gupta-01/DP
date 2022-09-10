// Same as Atcoder DP Contest E
// In usual Knapsck we maximise the value with state as DP(index,weight)
// Since the weights are very large, we use the states as DP(index, value) -> minimise the weight

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[105][1000005];

ll minmiseWeight(ll index,ll value_left,ll n, vector<ll> &values,vector<ll> &weights)
{
	if(value_left < 0){
		return 1e9;
	}

	if(index==n){
		if(value_left == 0){
			return 0;
		}
		return 1e9;;
	}

	if(dp[index][value_left]!=-1){
		return dp[index][value_left];
	}

	ll weight = 1e9;

	weight = min(weight, weights[index] + minmiseWeight(index+1,value_left - values[index],n,values,weights));

	weight = min(weight, minmiseWeight(index+1,value_left,n,values,weights));

	return dp[index][value_left] = weight;

}
int main()
{
	ll n,w;
	cin>>n>>w;

	vector<ll> weights(n);
	vector<ll> values(n);

	memset(dp, -1, sizeof dp);

	ll total = 0;

	for(ll i=0;i<n;i++){

		cin>>weights[i];
		cin>>values[i];
		total += values[i];

	}

	ll res = -1;

	for(ll value = 0 ;value<=total; value ++)
	{
		ll minWeight = minmiseWeight(0,value,n,values,weights);
		if(minWeight <= w){
			res = value;
		}
	}

	cout<<res;
	
}


