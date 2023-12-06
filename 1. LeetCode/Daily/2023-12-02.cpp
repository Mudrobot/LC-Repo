#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pass_now(1001,0);
        // 这里需要排一个序
        sort(trips.begin(),trips.end(),[](vector<int> &a,vector<int> &b){
            if(a[1] == b[1])return a[2]<b[2];
            else return a[1]<b[1];
        });
        int max_dis = 0;
        for(auto &trip:trips){
            pass_now[trip[1]] += trip[0];
            pass_now[trip[2]] -= trip[0];
            max_dis = max(max_dis,trip[2]);
        }
        int now = 0;
        for(int i=0;i<=max_dis;i++){
            now += pass_now[i];
            if(now>capacity)return false;
        }
        return true;
    }
};
int main(){
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    cout<<Solution().carPooling(trips,capacity);
    return 0;
}