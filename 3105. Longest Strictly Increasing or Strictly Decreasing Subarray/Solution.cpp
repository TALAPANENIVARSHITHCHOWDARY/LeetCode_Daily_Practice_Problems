#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longestMonotonicSubarray(vector<int>& nums){
        int n=nums.size();
        if(n==1)return 1;
        int maxi=1,maxd=1,curi=1,curd=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                curi++;
                maxi=max(maxi,curi);
                curd=1;
            }else if(nums[i]<nums[i-1]){
                curd++;
                maxd=max(maxd,curd);
                curi=1;
            }else{
                curi=1;
                curd=1;
            }
        }
        return max(maxi,maxd);
    }
};