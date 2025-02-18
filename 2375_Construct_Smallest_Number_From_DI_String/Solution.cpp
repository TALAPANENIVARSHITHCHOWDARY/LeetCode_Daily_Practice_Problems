#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            string num(n + 1, '0');
            for (int i = 0; i <= n; ++i) {
                num[i] = '1' + i;
            }
            for (int i = 0; i < n; ++i) {
                if (pattern[i] == 'D') {
                    int j = i;
                    while (j < n && pattern[j] == 'D') {
                        ++j;
                    }
                    reverse(num.begin() + i, num.begin() + j + 1);
                    i = j - 1;
                }
            }
            return num;
        }
    };