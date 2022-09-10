//Find the number of binary strings of length n where “0100” is not present 
// 1. as a substring.

#include<bits/stdc++.h>
using namespace std;

int dp[100005][8];  // 8 since we store last 3 binary characters , has total 2^3 total combinations

// In this case we maintan a maks for the last three characters seen befire this particular index under observvation
// At each indec, we decide if this transitions leads to a valid transition by checking for a value
// E.g. - to match 0100 , we maintain check if the mask is ever 010 i.e. 2 , then we only have to allow transition to 1 and not 0

int countBinarySubstringNotContainingT(int index,int lastThree, int n)
{
	if(index == n){
		return 1; // Since we haven't found any invalid substring as of now
	}	

	if(dp[index][lastThree]!=-1){
		return dp[index][lastThree];
	}

	int ans = 0;
	if(index >= 3 && lastThree == 2){  // But only lastThree ==2 condition will give 7 as ans and not 8, because it evaluates 10 and 010 both as 2. To Differentiate this, we will add a level logic

		ans = countBinarySubstringNotContainingT(index+1,5,n);   // written 5 but it means ((lastThree<<1) | 1 )& 111; |1  since we select 1 and &111 since we only need last 3
	}else{

		// either select 0 or 1
		ans = countBinarySubstringNotContainingT(index+1, (((lastThree<<1)|1)&7) , n);
		ans += countBinarySubstringNotContainingT(index+1, (((lastThree<<1)|0)&7) , n);
	}

	return dp[index][lastThree] = ans;
}

// Using Finite automata transitions

int state[1000005][5];
int recUsingAutomata(int index,int match,int n)
{
	// Prunning
	if(match == 4){
		return 0;
	}

	// Base Case
	if(index == n){
		return 1;
	}

	if(state[index][match]!=-1){
		return state[index][match];
	}

	int ans = 0;

	if(match == 0){
		ans  = recUsingAutomata(index+1,0,n) + recUsingAutomata(index+1,1,n);  // Case for 1 and 0 respectively
	}
	else if(match == 1)
	{
		ans = recUsingAutomata(index+1,2,n) + recUsingAutomata(index+1,1,n);
	}
	else if(match == 2)
	{
		ans = recUsingAutomata(index+1,0,n) + recUsingAutomata(index+1,3,n);
	}
	else if(match==3)
	{
		ans = recUsingAutomata(index+1,2,n) + recUsingAutomata(index+1,4,n);
	}

	return state[index][match] = ans;
}


int pw(int a,int b,int p){
   if(b==0)return 1;
   int t=pw(a,b/2,p);
   t=(t*t)%p;
   if(b%2)return (a*t)%p;
   return t;
}

int iterative()
{
	int dp[100001][5];
	dp[0][0] = 1;
       for (int i = 1; i <= 1000000; ++i) {
           for (int j = 0; j <= 4; ++j) {
               // 0100
               vector<int> v;
               if(j == 0) {  
                   v = {0, 2};   // Each vector stores the staes  through which we can reach state j
               }
               else if(j == 1) {
                   v = {0,1};
               }
               else if(j == 2) {
                   v = {1, 3};
               }
               else if(j == 3) {
                   v = {2};
               }
               else {
                   v = {3, 4, 4};
               }
               for (int k:v) {

               	   // For value j, we iterate the previous states through which we could have reached and add it in the answer.
                   dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
               }
           }
       }
}

void solve()
{
	int n;
	cin>>n;
	
	memset(dp, -1, sizeof dp);

	string t = "0100";


	// cout<<countBinarySubstringNotContainingT(0,0,n)<<"\n";


	memset(state, -1, sizeof state);
	cout<<recUsingAutomata(0,0,n)<<"\n";


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
