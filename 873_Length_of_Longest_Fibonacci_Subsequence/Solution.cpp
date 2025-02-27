#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;
        
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int ai = arr[k] - arr[j];
                if(ai < arr[j] && index.count(ai)) {
                    int i = index[ai];
                    dp[j][k] = dp[i][j] + 1;
                }
                maxLen = max(maxLen, dp[j][k]);
            }
        }
        
        return maxLen >= 3 ? maxLen : 0;
    }
};