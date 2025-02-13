#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            for(int num : nums) {
                pq.push((long long)num);
            }
            int ops = 0;
            while(pq.size() >= 2 && pq.top() < k) {
                long long x = pq.top(); pq.pop();
                long long y = pq.top(); pq.pop();
                long long newVal = min(x, y) * 2 + max(x, y);
                pq.push(newVal);
                ops++;
            }
            return ops;
        }
    };