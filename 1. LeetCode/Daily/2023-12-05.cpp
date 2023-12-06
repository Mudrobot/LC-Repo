#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> edge(roads.size()+1);
        for(auto &road:roads) {
            int u = road[0],v = road[1];
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int ans = 0;
        function<int(int, int)> dfs = [&](int u,int fa) {
            if (edge[u].size()==1&&u!=0){
                ans += 1;
                return 1;
            }
            int size = 0;
            for (auto &v:edge[u]){
                if (v == fa) continue;
                size += dfs(v,u);
            }
            if (u!=0) ans += (size) / seats + 1; // ceil((size+1)/seats)
            return size+1;
        };
        dfs(0,-1);
        return ans;
    }
};
int main(){
    vector<vector<int>> roads = {{0,1},{1,2}};
    int seats = 5;
    cout << Solution().minimumFuelCost(roads, seats) << endl;
    return 0;
}