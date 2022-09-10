#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int findMaxTime(int row, int col, vector<vector<int>> &v)
{
    // cout<<row<<" "<<col<<"\n";
    if(row <0 || col < 0 || row >=v.size() || col >= v[0].size() ){
        return INT_MIN;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    int ld = findMaxTime(row-1,col-1,v);
    int rd = findMaxTime(row-1,col+1,v);
    int up = findMaxTime(row-1,col,v);

    return dp[row][col] = max( {v[row][col],ld,rd,up} );
}
int main() {

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp, -1, sizeof dp);
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                cin>>v[i][j];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int maxTime = findMaxTime(i,j,v);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j] >= dp[i][j]){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }
            cout<<"\n";
        }
    }

}