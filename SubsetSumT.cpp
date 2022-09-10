#include<bits/stdc++.h>
using namespace std;

// n<=100
// T <=10^4
// 
int dp[105][10010];

bool subsetSumT(int index, int currSum, int n, int T, vector<int> &v)
{
	if(currSum > T){
		return dp[index][currSum]= false;
	}
	if(index==n)
	{
		if(currSum == T){
			return dp[index][currSum] = true;
		}
		return dp[index][currSum] = false;
	}

	if(dp[index][currSum]!=-1){
		return dp[index][currSum];
	}

	bool take = subsetSumT(index+1,currSum+v[index], n, T, v);

	bool notTake = subsetSumT(index+1,currSum,n,T,v);

	return dp[index][currSum] = (take|notTake);
}

// This function is optimised form of the previous function, as it allows us to work on queries.
// The former function tracked what sum has been taken till [0...level-1], but this function tracks 
// what sum is left to be taken from [level...N-1]

int subsetSumOptimised(int index, int left, int n, vector<int> &v)
{

	if(left < 0){
		return 0;
	}

	if(index==n)
	{
		if(left == 0){
			return 1;
		}
		return 0;
	}

	if(dp[index][left]!=-1){
		return dp[index][left];
	}

	int taken = subsetSumOptimised(index+1,left - v[index],n,v);

	int notTaken = subsetSumOptimised(index+1,left,n,v);

	return dp[index][left] = taken | notTaken ;
}

// In order to use the DP array , memoise the base cases as well
void printSolution(int index, int left, int n, vector<int> &v)
{
	// Printing States
	cout<<"Printer :"<<index<<" "<<left<<"\n";



	// Base Case
	if(index==n)
	{
		return;
	}

	// Find the correct transition

	// Take transition
	if(subsetSumOptimised(index+1,left-v[index],n,v)){

		cout<< v[index] <<" ";
		printSolution(index+1,left-v[index], n, v);
	}

	// Not Take Transition
	else if(subsetSumOptimised(index+1,left,n,v))
	{
		printSolution(index+1,left,n,v);
	}
}

// Uses Backtracking to get All solutions -> Exponential Time Complexity
void printAllSolutions(int index, int left, int n, vector<int> &v, vector<int> &curr)
{
	if(index==n)
	{
        for(auto &val:curr)
        {
            cout<<val<<" ";
        }
		cout<<'\n';
		return;
	}
    if(subsetSumOptimised(index+1,left,n,v)==1)
    {
        printAllSolutions(index+1,left,n,v,curr);
    }
	if(subsetSumOptimised(index+1,left - v[index],n,v)==1){
		curr.push_back(v[index]);
        printAllSolutions(index+1,left - v[index],n,v,curr);
        curr.pop_back();
	}

}


int main()
{
	// int n,t;
	// cin>>n>>t;

	// memset(dp, -1, sizeof dp);

	// vector<int> v(n);

	// for(int i=0;i<n;i++)
	// {
	// 	cin>>v[i];
	// }

	// bool exists = subsetSumT(0,0,n,t,v);
	// if(exists){
	// 	cout<<"YES";
	// }else{
	// 	cout<<"NO";
	// }

	int n,testCases;
	cin>>n>>testCases;


	memset(dp, -1, sizeof dp);
	vector<int> v(n);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	while(testCases--)
	{
		int totalSum;
		cin>>totalSum;
		bool isPossibleSum = subsetSumOptimised(0,totalSum,n,v);
		cout<<isPossibleSum<<"\n";
		if(isPossibleSum)
		{
			printSolution(0,totalSum,n,v);
		}else{
			cout<<"No Solution";
		}
		cout<<"\n";
	}

}