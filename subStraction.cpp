#include<bits/stdc++.h>
using namespace std;


int dp[100005];

// 1 - win , 0 - lose

int substraction(int x)
{
	if(x==0){
		return 0;
	}

	if(dp[x]!=-1){
		return dp[x];
	}

	int ans = 0;
	for(int m=0; (1<<m) <= x; m++){

		// If any subsequant state (played by player 2) is losing, we win
		if(substraction(x - (1<<m)) == 0 ){
			ans = 1;
		}
	}

	return dp[x] = ans;

}
int main()
{
	int x;
	cin>>x;

	memset(dp,-1,sizeof dp);

	for(int i=0;i<=100;i++)
	{
		cout<<i<<" "<<substraction(i)<<"\n";
	}

	// Now observe a pattern
	// 0 1 1 0 1 1 0 1 1 0 1 1 
	// Now the soltutions

	if(n%3){
		cout<<"Win";
	}else{
		cout<<"Lose";
	}
}