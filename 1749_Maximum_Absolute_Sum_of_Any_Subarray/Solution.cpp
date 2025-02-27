#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int mini = 0, maxi = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                mini = min(mini, sum);
                maxi = max(maxi, sum);
            }
            return maxi - mini;
        }
    };
    
