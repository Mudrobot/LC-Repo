#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<n;++i) dp[0][i] = grid[0][i];
        for(int i=1;i<m;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    if(k==0) dp[i][j] = dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j];
                    else dp[i][j] = min(dp[i][j],dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
                }
            }
        }
        int maxx = dp[m-1][0];
        for(int i=0;i<n;++i) maxx = min(maxx,dp[m-1][i]);
        return maxx;
    }
};
int main(){
    vector<vector<int>> grid = {{5,3},{4,0},{2,1}},moveCost = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
    cout<<Solution().minPathCost(grid,moveCost)<<endl;
    return 0;
}