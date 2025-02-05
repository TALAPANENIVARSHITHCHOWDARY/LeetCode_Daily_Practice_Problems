#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> arr;
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2) return false;
                arr.push_back(i);
            }
        }
        if (cnt == 0) return true;
        if (cnt == 2 && s1[arr[0]] == s2[arr[1]] && s1[arr[1]] == s2[arr[0]]) return true;
        return false;
    }
};