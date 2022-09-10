#include <iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int> findLISAtI(vector<int>& arr, int n)
{
    vector<int> inserted(n);
    vector<int> lis;
   
    for(int i=0;i<n;i++)
    {
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
            inserted[i] = lis.size();
        }else{
            auto it = lower_bound(begin(lis),end(lis),arr[i]);
            *it = arr[i];
            inserted[i] = it - begin(lis) + 1;
        }
    }
    
    return inserted;
}
int longestBitonicSequence(vector<int>& arr, int n) {
    
    vector<int> increase = findLISAtI(arr,n);
    reverse(begin(arr),end(arr));
    vector<int> decrease = findLISAtI(arr,n);
    reverse(begin(decrease),end(decrease));

    int longest = 0;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<increase[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<n;i++)
    // {
    //     cout<<decrease[i]<<' ';
    // }
    // cout<<'\n';
    for(int i=0;i<n;i++)
    {
        longest = max(longest, increase[i] + decrease[i] -1 );
    }
    return longest;
} 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<longestBitonicSequence(arr,n)<<'\n';
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
