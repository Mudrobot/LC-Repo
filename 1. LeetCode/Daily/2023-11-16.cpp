/*
2760. 最长奇偶子数组
https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/description/?envType=daily-question&envId=2023-11-16
*/ 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0]%2==0&&nums[0]<=threshold?1:0;
        for(int i=1;i<len;i++){
            if(nums[i]%2==0 && nums[i]<=threshold) dp[i] = 1;
            if((nums[i]%2)+(nums[i-1]%2)==1 && nums[i]<=threshold && dp[i-1]) dp[i] = max(dp[i],dp[i-1]+1);
        }
        int max_int = dp[0];
        for(auto d:dp){
            max_int = max_int>d?max_int:d;
        }
        return max_int;
    }
};
int main(){
    vector<int> nums = {1,10,5}; // 创建一个vector<int>类型的实例
    int threshold = 9;
    int a = Solution().longestAlternatingSubarray(nums, threshold);
    cout << a << endl;
    return 0;
}