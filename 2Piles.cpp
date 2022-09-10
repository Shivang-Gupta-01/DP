#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int twoPiles(int a, int b)
{
	if( a==0 && b==0 ){
		return 0;
	}

	if(dp[a][b]!=-1){
		return dp[a][b];
	}
	int ans = 0;
	
	// Take from Pile A
	for(int i=1;i<=a;i++){
		if(twoPiles(a-i,b)==0){
			ans = 1;
			break;
		}
	}

	// Take from Pile B
	for(int i=1;i<=b;i++){
		if(twoPiles(a,b-i)==0){
			ans = 1;
			break;
		}
	}
	
	// Take from Both

	for(int i=1;i<=min(a,b);i++){
		if(twoPiles(a-i,b-i)==0){
			ans = 1;
			break;
		}
	}

	return dp[a][b] = ans;

}

int twoPilesIterative(int a,int b)
{

	int dp[1005][1005];
	memset(dp,-1,sizeof dp);


	for(int x = 0; x<=a; x++)
	{
		for(int y = 0; y<=b; y++)
		{

			if(x==0 && y==0){
				dp[x][y] = 0;
			}

			int ans = 0;

			for(int i=1;i<=x;i++){
				if(dp[x-i][y] == 0){
					ans = 1;
					break;
				}
			}

			for(int i=1;i<=y;i++){
				if(dp[x][y-i] == 0){
					ans = 1;
					break;
				}
			}

			for(int i=1;i<=min(x,y);i++){
				if(dp[x-i][y-i] == 0){
					ans = 1;
					break;
				}
			}
			dp[x][y] = ans;
		}
	}

	return dp[a][b];
}
void solve()
{
	int a,b;
	cin>>a>>b;

	memset(dp, -1, sizeof dp);
	cout<<twoPiles(a,b)<<" ";
	cout<<twoPilesIterative(a,b)<<"\n";
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