#include<bits/stdc++.h>
using namespace std;

int minimisePenalty(int n, int m, int k)
{

	if(n<=0 || m<=0){
		return 0;
	}

	if(k==1)
	{
		return pow(n*m,2);
	}

	int cut = INT_MAX;

	for(int i=1;i<=n;i++)
	{
		int area = pow(i*m,2);
		cut = area + min(minimisePenalty(n-i,m,k-1),minimisePenalty(m,n-i,k-1));
	}

	return cut;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	cout<< min(minimisePenalty(n,m,k),minimisePenalty(m,n,k));
}