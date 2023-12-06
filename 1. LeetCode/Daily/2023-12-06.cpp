#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> nums(n+1,0);
        vector<vector<int>> edge(n+1);
        for(auto &tmp:edges){
            int u = tmp[0], v = tmp[1];
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        function<bool(int,int,int)> dfs = [&](int u,int fa,int tar) { 
            if (u == tar){
                nums[u]++; return true;
            }
            for(auto &v:edge[u]){
                if (v == fa) continue;
                if (dfs(v,u,tar)) {
                    nums[u]+=1;
                    return true;
                }
            }
            return false;
        };
        for(auto &trip:trips) { 
            dfs(trip[0],-1,trip[1]);
        }
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        function <void(int,int)> dfs_dp = [&](int u,int fa) {
            dp[u][0] = price[u]*nums[u];
            dp[u][1] = price[u]*nums[u]/2;
            for(auto &v:edge[u]){
                if (v==fa) continue;
                dfs_dp(v,u);
                dp[u][0] += min(dp[v][0],dp[v][1]);
                dp[u][1] += dp[v][0];
            }   
        };
        dfs_dp(0,-1);
        return min(dp[0][0],dp[0][1]);
    }
};
int main() {
    int n = 4;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3}};
    vector<int> price = {2,2,10,6};
    vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
    cout << Solution().minimumTotalPrice(n,edges,price,trips) << endl;
    return 0;
}