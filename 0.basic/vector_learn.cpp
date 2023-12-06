#include<bits/stdc++.h>
using namespace std;
vector<int> nums = {1, 5, 3, 9, 2};
int main(){
    // 循环
    for(auto num:nums){ //建议写成 for(auto &num:nums)
        printf("%d\n",num);
    }
    return 0;
}