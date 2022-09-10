#include<bits/stdc++.h>
using namespace std;
// There are 2 variants of the porblem depending on the cost function
// The cost may either be dependant on the vertices or it may depend on the edge.
// When the cost is dependant on the vertices, no extra checks are required while iterating throught all options between l and r
// However in cases when it is (e.e. permiter, sin function of edge) then , there are 2 cases when the value of l+1<=k<=r-1
// has to be handled. 
// These are k = l+1 and l = r-1
// For these cases since the edge is already connected to l and r, no extra cost is required from the left and right part simlutaneously
// This code illustrates the same.



double dp[101][101];
bool done[101][101];

double sq(double x)
{
	return x*x;
}

double cost(int x, int y, pair<double,double> *p)
{
	double dist = sqrt( sq(p[x].first - p[y].first) +  sq(p[x].second - p[y].second) );
	return sin(dist);
}

double triangulationCost(int l, int r,pair<double,double> *points)
{
	if(l+2==r){
		return 0;
	}

	if(done[l][r]){
		return dp[l][r];
	}

	double res = 1e9;

	for(int i=l+1; i<=r-1; i++)
	{
		if(i == l+1){
			res = min(res, cost(l+1,r,points) + triangulationCost(l+1,r,points));
		}
		else if(i == r-1){
			res = min(res,cost(r-1,l,points) + triangulationCost(l,r-1,points));
		}
		else{
			res = min( res, cost(l,i,points) + cost(i,r,points) + triangulationCost(l,i,points) + triangulationCost(i,r,points));
		}
	}

	done[l][r] = true;
	return dp[l][r] = res;
}

double triangulationCostIterative(int n, pair<double,double> *points)
{
	double dp[n+1][n+1];
	memset(dp, 0.0, sizeof dp);

	for(int len = 3; len <=n ; len++){
		for(int l = 1; l+len-1<=n;l++){

			int r = l + len - 1;

			if(len == 3){
				dp[l][r] = 0;
				continue;
			}

			double ans = 1e9;

			for(int k = l+1; k<=r-1; k++){

				if(k == l+1)
				{
					ans = min(ans,cost(l+1,r,points) + dp[l+1][r]);
				}else if(k == r-1){
					ans = min(ans,cost(l,r-1,points) + dp[l][r-1]);
				}else{
					ans = min(ans, cost(l,k,points) + cost(k,r,points) + dp[l][k] + dp[k][r]);
				}
			}

			dp[l][r] = ans;
		}
	}

	return dp[1][n];
} 
void solve()
{
	int n;
	cin>>n;
	pair<double,double> points[101];


	memset(dp, -1.0, sizeof dp);
	memset(done, false, sizeof done);

	for(int i=1;i<=n;i++)
	{
		cin>>points[i].first>>points[i].second;
	}

	cout<<triangulationCost(1,n,points)<<" ";
	cout<<triangulationCostIterative(n,points)<<" ";

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