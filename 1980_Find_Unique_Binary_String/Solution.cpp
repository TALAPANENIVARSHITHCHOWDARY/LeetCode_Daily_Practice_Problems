#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
       public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            unordered_set<string> numSet(nums.begin(), nums.end());
            string current(n, '0');
            if (backtrack(numSet, current, 0, n)) {
                return current;
            }
            return "";
        }
    
    private:
        bool backtrack(unordered_set<string>& numSet, string& current, int pos, int n) {
            if (pos == n) {
                return numSet.find(current) == numSet.end();
            }
            if (backtrack(numSet, current, pos + 1, n)) {
                return true;
            }
            current[pos] = '1';
            if (backtrack(numSet, current, pos + 1, n)) {
                return true;
            }
            current[pos] = '0';
            return false;
        }
    };