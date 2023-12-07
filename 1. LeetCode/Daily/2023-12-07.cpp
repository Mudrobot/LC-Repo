#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> edge(n+1);
        for(auto &c:connections){
            int a = c[0], b = c[1];
            edge[a].push_back({b,1});
            edge[b].push_back({a,0});
        }
        int ans = 0;
        function<void(int,int)> dfs = [&](int u,int fa){
            for(auto &[v,type]:edge[u]){
                if(v==fa) continue;
                ans += type;
                dfs(v,u);
            }
        };
        dfs(0,-1);
        return ans;
    }
};
int main(){
    int n=6;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << Solution().minReorder(n, connections) << endl;
    return 0;
}