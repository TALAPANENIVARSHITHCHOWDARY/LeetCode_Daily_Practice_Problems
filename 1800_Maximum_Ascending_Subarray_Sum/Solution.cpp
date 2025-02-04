#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int cur=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cur+=nums[i];
            }else{
                maxi=max(maxi,cur);
                cur=nums[i];
            }
        }
            maxi=max(cur,maxi);
            return maxi;
    }
};