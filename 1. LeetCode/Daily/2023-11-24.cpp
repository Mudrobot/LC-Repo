#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(),cnt=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(nums[i]+nums[j] < target)
                    ++cnt;
            }
        }
        return cnt;
    }
};
int main() {
    vector<int> nums = {-1, 1, 2, 3, 1};
    int target = 2;
    cout<<Solution().countPairs(nums, target);
    return 0;
}