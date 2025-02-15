#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool func(int sind, int sum, string snum, int tar, vector<vector<int>>& dp) {
        if (sind == snum.size()) {
            return sum == tar;
        }
        if (sum > tar) return false;
        if (dp[sind][sum] != -1) return dp[sind][sum];
        bool ind = false;
        for (int curi = sind; curi < snum.size(); curi++) {
            string curs = snum.substr(sind, curi - sind + 1);
            int addend = stoi(curs);
            ind = ind || func(curi + 1, sum + addend, snum, tar, dp);
            if (ind == true) return true;
        }
        return dp[sind][sum] = ind;
    }
    int punishmentNumber(int n) {
        int result = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            string snum = to_string(squareNum);
            vector<vector<int>> dp(snum.size(), vector<int>(currentNum + 1, -1));
            if (func(0, 0, snum, currentNum, dp)) {
                result += squareNum;
            }
        }
        return result;
    }
};
