#include<bits/stdc++.h>
using namespace std;

int dp[25][10000];

int maxValue(int n,int maxWeight, vector<int> &value, vector<int> &weight)
{
    if(maxWeight<0){
        return INT_MIN;
    }
    if(n == -1)
    {
        return 0;
    }
    
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    
    int take = value[n] + maxValue(n-1,maxWeight-weight[n],value,weight);
    
    int notTake = maxValue(n-1,maxWeight,value,weight);
    
    return dp[n][maxWeight] = max(take,notTake);
}

int knapSakcIterative(int n,int maxWeight, vector<int> &value, vector<int> &weight)
{
    int dp[105][10005];

    for(int w = 0; w<=maxWeight; w++)
    {
        dp[n][w] = 0;
    }

    for(int i = n-1; i>=0;i--)
    {
        for(int w = 0; w <= maxWeight ; w++)
        {
            dp[i][w] = dp[i+1][w];

            if(w + weight[i] <= maxWeight){
                dp[i][w] = max(dp[i][w], value[i]+dp[i+1][w + weight[i]]);
            }
        }
    }


    for(int i=0;i<=n;i++){
        for(int w = 0; w<=maxWeight; w++){
            cout<<dp[i][w]<<' ';
        }
        cout<<'\n';
    }

    return dp[0][0];


}
void printSolution(int n,int currValue,int maxWeight,vector<int> &value, vector<int> &weight){

    if( n == -1 )
    {
        return;
    }
    
    if(maxValue(n-1,maxWeight-weight[n],value,weight) == currValue - value[n]){
        cout<< value[n] <<" "<<weight[n] <<'\n';
        printSolution(n-1,currValue - value[n],maxWeight-weight[n],value,weight);
    }
    else if( maxValue(n-1,maxWeight,value,weight) == currValue){
        printSolution(n-1,currValue,maxWeight,value,weight);
    }
}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> value(n);
    vector<int> weight(n);
    
    memset(dp, -1, sizeof dp);

    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i];
    }
    
    // int maxv = maxValue(n-1,w,value,weight);  
    // cout<<maxv<<"\n";
    // cout<< maxValue(1,30,3,value,weight);
    // printSolution(n-1,maxv,w,value,weight);
    knapSakcIterative(n,w,value,weight);

}