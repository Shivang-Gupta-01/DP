//Find the number of binary strings of length n where “0100” is not present 
// 1. as a subsequance.

#include<bits/stdc++.h>
using namespace std;

// match = 0 -> For empty substring
//         1 -> {0}
//         2 -> {01}
//         3 -> {010}
//         4 -> {0100}

int dp[100005][5];  // 5 States corresponse to 5 types of prefix Seen

int countBinarySubstringNotContainingT(int index,int prefixSeenSoFar, int n)
{

	// Prunning
	if(prefixSeenSoFar == 4){
		return 0;  // Since substring already created
	}

	if(index == n){
		return 1;  // Since we have already used the above condition to check if we got a subsequance or not, in all other scenarios, we dont get it and therefore return 1
	}

	if(dp[index][prefixSeenSoFar]!=-1){
		return dp[index][prefixSeenSoFar];
	}


	// We can either match with the current character in T or not Match
	int ans = countBinarySubstringNotContainingT(index+1,prefixSeenSoFar+1,n) + countBinarySubstringNotContainingT(index+1,prefixSeenSoFar,n);

	return dp[index][prefixSeenSoFar] = ans;


}
void solve()
{
	int n;
	cin>>n;
	
	memset(dp, -1, sizeof dp);

	string t = "0100";
	// Only the length of the stirng T is used, since it is binary string


	cout<<countBinarySubstringNotContainingT(0,0,n)<<"\n";

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin>>t;

	while(t--)
	{
		solve();
	}

}