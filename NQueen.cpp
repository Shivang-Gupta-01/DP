#include<bits/stdc++.h>
using namespace std;

int column = 0 ;
int ld = 0;
int rd = 0;

int countWays(int row, int n)
{

	if(row == n+1){
		return  1;
	}


	int ways = 0;

	for(int col = 1; col<=n; col++)
	{
		if((column & (1<<col)) || (ld & (1<<(row + col))) || (rd & (1<<(n+row-col)))){
			continue;
		}

		column |= (1<<col);
		ld |= (1<<(row + col));
		rd |= (1<<(n+row-col));

		ways += countWays(row+1,n);

		column ^= (1<<col);
		ld ^= (1<<(row + col));
		rd ^= (1<<(n+row-col));
	}

	return ways;

}

int main()
{
	int n;
	cin>>n;

	cout<<countWays(1,n);
}


