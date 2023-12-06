/*
53. 最大子数组和
https://leetcode.cn/problems/maximum-subarray/description/?envType=daily-question&envId=2023-11-20
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for(int i=2;i<=n;++i){
            dp[i] = max(dp[i-1]+nums[i-1],nums[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
int main(){
    vector<int> nums = {5,4,-1,7,8};
    cout<<Solution().maxSubArray(nums)<<endl;
    return 0;
}