#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1;  // Initialize with empty subarray (even sum)
        int prefixSum = 0;
        int result = 0;
        
        for(int num : arr) {
            prefixSum += num;
            if(prefixSum % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }
        
        return result;
    }
};