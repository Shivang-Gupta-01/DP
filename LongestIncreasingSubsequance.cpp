#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int dp2[100005];
// Using Form 1
int LIS(int index,int n,int prev,vector<int> &v)
{
    if(index == n){
        return 0;
    }

    if(dp[index][prev]!=-1){
        return dp[index][prev];
    }

    int take = INT_MIN;
    if(v[index] > prev){
        take = 1 + LIS(index+1,n,v[index],v);
    }

    int notTake = LIS(index+1,n,prev,v);

    return dp[index][prev] = max(take,notTake);
}

int LIS2(int index,vector<int> &v)
{
    if(index==0){
        return 1;
    }

    if(dp2[index]!=-1){
        return dp2[index];
    }

    int lis = 1;
    for(int i = index-1; i>=0 ; i--)
    {
        if(v[index] > v[i]){

            lis = max(lis,1 + LIS2(i,v));
        }
    }

    return dp2[index] = lis;
}

// LIS using Nlogn
int optimalLIS(int n,vector<int> &v)
{
    vector<int> lis;

    for(int i=0;i<n;i++)
    {
        if(lis.size()==0 || lis.back()<v[i]){
            lis.push_back(v[i]);
        }
        else{
            int pos = lower_bound(begin(lis),end(lis),v[i]) - begin(lis);
            lis[pos] = v[i];
        }
    }
    return lis.size();
}

// Finding the solution using optimal LIS
int printLIS(int n,vector<int> &v)
{
    vector<int> lis;
    int insertedAt[n];

    for(int i=0;i<n;i++)
    {
        if(lis.size()==0 || lis.back()<v[i]){
            lis.push_back(v[i]);
            insertedAt[i] = lis.size(); // Since this indx at arr, is inserted at the end of the LIS
        }
        else{
            int pos = lower_bound(begin(lis),end(lis),v[i]) - begin(lis);
            lis[pos] = v[i];
            insertedAt[i] = pos+1;        // // Since this indx at arr, is inserted at pos + 1 length
        }

        for(int i=0;i<lis.size();i++)
        {
            cout<<lis[i]<<" ";        
        }
        cout<<"\n";
    }


    for(int i=0;i<n;i++)
    {
        cout<<insertedAt[i]<<" ";
    }

    cout<<'\n';

    // Print the Inserted Array
    vector<int> print;

    int currLevel = lis.size();

    for(int i = n-1 ; i>=0 ; i--){

        if(insertedAt[i]==currLevel){
            print.push_back(v[i]);
            currLevel--;
        }
    }

    reverse(begin(print),end(print));

    for(auto &val:print){
        cout<<val<<" ";
    }
    cout<<'\n';


    return lis.size();
}

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    // Using prev = 0 as dp[index][-ve] value won't give correct result 
    cout<<LIS(0,n,0,v)<<"\n";


    // Using Form 2
    int lis = 0;

    // since whatever is the LIS will end at some index, we have to iterate through 
    for(int i=0;i<n;i++)
    {
        int len = LIS2(i,v);
        cout<<len<<" ";
        lis = max(lis,len);

    }
    cout<<"\n";

    cout<<lis;
    cout<<"\n";

    cout<<optimalLIS(n,v);
    cout<<"\n";
    cout<<"\n";

    cout<<printLIS(n,v);
}

// 10
// 1 5 7 10 9 6 7 9 2 3 