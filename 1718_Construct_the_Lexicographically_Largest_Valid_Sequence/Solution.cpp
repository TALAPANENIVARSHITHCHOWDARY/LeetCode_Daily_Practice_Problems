#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& result, vector<bool>& used, int pos, int n) {
        if (pos >= result.size()) return true;
        if (result[pos] != 0) return backtrack(result, used, pos + 1, n);
        
        for (int i = n; i >= 1; i--) {
            if (used[i]) continue;
            if (i != 1 && (pos + i >= result.size() || result[pos + i] != 0)) continue;
            
            used[i] = true;
            result[pos] = i;
            if (i != 1) result[pos + i] = i;
            
            if (backtrack(result, used, pos + 1, n)) return true;
            
            used[i] = false;
            result[pos] = 0;
            if (i != 1) result[pos + i] = 0;
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size);
        vector<bool> used(n + 1);
        backtrack(result, used, 0, n);
        return result;
    }
};