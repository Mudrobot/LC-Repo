#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int minus = 0;
        for(int i=0;i<nums.size()-1;i++){
            if((i-minus)%2==0 && nums[i] == nums[i+1])minus++;
        }
        if ((nums.size()-minus)%2==1) minus++;
        return minus;
    }
};
int main(){
    vector<int> input = {1,1,2,2,3,3};
    cout<<Solution().minDeletion(input);
    return 0;
}