#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll dp[100005];

int minTravelCost(ll index, ll n, ll k, vector<ll> &busFare, vector<ll> &flightFare)
{
	if(index==n-1){
		return 0;
	}
	if(dp[index]!=-1){
		return dp[index];
	}

	ll cost = 1e18;


	cost = min(cost,busFare[index] + minTravelCost(index+1,n,k,busFare,flightFare));

	for(int i=index+1; i<=index+k && i<n; i++)
	{

		cost = min(cost,flightFare[index] + flightFare[i] + minTravelCost(i,n,k,busFare,flightFare));
	}


	return dp[index] = cost;
}

// Using iterative structure, we can optimise the complexity from O(n*k) to O(n).
// we need to iterate through all previous k's, however to get the minimum result from the last k values we can use
// a deque. 
// Through this we can get the minimum in O(1). => TC = O(N)

ll minTravelCostIterative(ll n, ll k, vector<ll> &busFare, vector<ll> &flightFare){

	ll dp[n];
	dp[0] = 0;

	deque<ll> dq;

	for(ll level=1;level<=n-1;level++)
	{
		dp[level] = dp[level-1] + busFare[level-1];

		while(!dq.empty() && dp[level-1] + flightFare[level-1] < dp[dq.back()] + flightFare[dq.back()]){
			dq.pop_back();
		}

		dq.push_back(level-1);

		if(dq.front() <= level-k-1){
			dq.pop_front();
		}

		dp[level] = min(dp[level],dp[dq.front()] + flightFare[dq.front()] + flightFare[level]);
	}

	cout<<'\n';
	return dp[n-1];
}

ll dp2[1005][1005];

ll minTravelCostM(ll index, ll n, ll m, ll k, vector<ll> &busFare, vector<ll> &flightFare ){

	if(m < 0){
		return 1e18;
	}

	if(index==n-1){
		return 0;
	}

	if(dp2[index][m]!=-1){
		return dp2[index][m];
	}

	ll cost = 1e18;

	cost = min(cost , busFare[index] + minTravelCostM(index+1,n,m,k,busFare, flightFare));

	for(int i=index+1; i<=index+k && i<n; i++){

		cost = min(cost, flightFare[index] + flightFare[i] + minTravelCostM(i,n,m-1,k,busFare,flightFare));
	}
	return dp2[index][m] = cost;
}
// The reason 
ll minTravelCostMIterative(ll n, ll k, ll m, vector<ll> &busFare, vector<ll> &flightFare)
{
	ll dp[2][m+1];
	memset(dp,0,sizeof dp);

	// for(int j=0;j<=m;j++)
	// {
	// 	for(int i=0;i<n;i++)
	// 	{
	// 		if(i==0){
	// 			dp[j][i] = 0;
	// 		}else{
	// 			dp[j][i] = busFare[i-1] + dp[j][i-1];

	// 			if(j > 0)
	// 			{
	// 				for(int x = 1; x<=k; x++){
	// 					if(i-x >=0)
	// 					{
	// 						dp[j][i] = min(dp[j][i], dp[j-1][i-x] + flightFare[i] + flightFare[i-x]);
	// 					}
						
	// 				}
	// 			}
	// 		}

	// 	}
	// }

	// /*
	// for(int j=0;j<=m;j++)
	// {
	// 	for(int i=0;i<n;i++){
	// 		cout<<dp[j][i]<<' ';
	// 	}
	// 	cout<<"\n";
	// }
	// */	
	// return dp[m][n-1];
	// We can again optimise this using dequeu and since j is only dependant on j and j-1, we only need prev and curr rows
	// We can do j&1 and (j-1)&1 to store the same

	for(int j = 0; j<=m ;j++){

		deque<ll> dq;

		for(int i=0; i<n; i++){

			if(i==0){
				dp[j&1][i] = 0;
			}else{

				dp[j&1][i] = dp[j&1][i-1] + busFare[i-1];

				if(j > 0){

					while(!dq.empty() && dp[(j-1)&1][i-1] + flightFare[i-1] < dp[(j-1)&1][dq.back()] + flightFare[dq.back()]){
						dq.pop_back();
					}

					dq.push_back(i-1);

					if(dq.front() <= i-k-1){
						dq.pop_front();
					}

					dp[j&1][i] = min(dp[j&1][i],dp[(j-1)&1][dq.front()] + flightFare[dq.front()] + flightFare[i]);
				}
			}
		}
	}

	return dp[(m&1)][n-1];
}
void solve()
{
	ll n,m,k;
	cin>>n>>m>>k;

	memset(dp,-1,sizeof dp);
	memset(dp2,-1,sizeof dp2);

	vector<ll> busFare(n);
	vector<ll> flightFare(n);

	for(ll i=0;i<n;i++)
	{
		cin>>busFare[i];
	}

	for(ll i=0;i<n;i++)
	{
		cin>>flightFare[i];
	}

	cout<<minTravelCost(0,n,k,busFare,flightFare)<<" ";
	cout<<minTravelCostIterative(n,k,busFare,flightFare)<<"\n";

	cout<<minTravelCostM(0,n,m,k,busFare,flightFare)<<" ";
	cout<<minTravelCostMIterative(n,k,m,busFare,flightFare)<<" ";
}

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		solve();
	}
}