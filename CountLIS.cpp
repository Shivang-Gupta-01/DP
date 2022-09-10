#include<bits/stdc++.h>
#define int long long
using namespace std;

int LIS(int n,vector<int> &v)
{

    vector<int> len(n,1);
    vector<int> cnt(n,1);

    int lis = 1;

    for(int i=1;i<n;i++)
    {
        for(int j = 0; j<i ;j++){
            
            if(v[j] < v[i]){

                if(1 + len[j] > len[i]){
                     len[i] = 1 + len[j];
                    cnt[i] = cnt[j];
                }
                else if(1 + len[j] == len[i]){
                    cnt[i] += cnt[j];
                }
            }
        }
        lis = max(lis,len[i]);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<len[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<n;i++)
    // {
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<'\n';

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(lis == len[i]){
            ans += cnt[i];
        }
    }

    return ans;
}
void solve()
{

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<LIS(n,v);
    cout<<'\n';

}
signed main()
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