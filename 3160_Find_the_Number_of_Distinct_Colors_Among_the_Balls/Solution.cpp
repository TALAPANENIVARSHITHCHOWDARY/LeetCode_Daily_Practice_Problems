#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> result;
            unordered_map<int, int> mppB; 
            unordered_map<int, int> mppC; 
            int cnt = 0; 
            for (const auto& query : queries) {
                int ball = query[0];
                int color = query[1];
                if (mppB.find(ball) != mppB.end()) {
                    int oldColor = mppB[ball];
                    mppC[oldColor]--;
                    if (mppC[oldColor] == 0) {
                        cnt--;
                    }
                }
                mppB[ball] = color;
                mppC[color]++;
                if (mppC[color] == 1) {
                    cnt++;
                }
                result.push_back(cnt);
            }
            return result;
        }
    };