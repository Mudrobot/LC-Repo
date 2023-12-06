#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum_point = 0,n = cardPoints.size();
        for(auto &cardPoint:cardPoints)sum_point+=cardPoint;
        int res = n-k;
        int minn,capa=0,now=0;
        for(int i=0;i<n;++i){
            if (capa<res) now += cardPoints[i], capa += 1;
            else {
                if(i == res) minn = now;
                now = now - cardPoints[i-res] + cardPoints[i];
                minn = min(minn,now);
            }
        }
        return sum_point - minn;
    }
};
int main(){
    vector<int> cardPoints={1,2,3,4,5,6,1};
    cout << Solution().maxScore(cardPoints, 3) << endl;
    return 0;
}