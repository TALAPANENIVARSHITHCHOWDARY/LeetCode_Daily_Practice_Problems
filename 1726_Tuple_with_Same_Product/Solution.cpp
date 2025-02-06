#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                productCount[nums[i] * nums[j]]++;
            }
        }
        int result = 0;
        for(auto& p : productCount) {
            if(p.second > 1) {
                result += p.second * (p.second-1) * 4;
            }
        }
        return result;
    }
};