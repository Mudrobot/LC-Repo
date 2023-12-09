#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[1]==b[1])return a[0] < b[0];
            return a[1] < b[1];
        });
        int p_num = rides.size();
        vector<long long> dp(p_num+1);
        for(int i=0;i<p_num;++i){
            int j = upper_bound(rides.begin(), rides.begin() + i, rides[i][0], [](int x, const vector<int> &r){
                return x < r[1];
            }) - rides.begin();
            dp[i+1] = max(dp[i], dp[j]+rides[i][1]-rides[i][0]+rides[i][2]);
        }
        return dp[p_num];
    }
};
int main(){
    vector<vector<int>> rides = {{2,5,4},{1,5,1}};

}