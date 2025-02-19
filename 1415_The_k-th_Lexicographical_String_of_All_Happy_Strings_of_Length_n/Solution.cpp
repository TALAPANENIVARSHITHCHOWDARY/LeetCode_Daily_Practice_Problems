#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void func(int n, string &cur, vector<string> &arr, char lc) {
            if (cur.size() == n) {
                arr.push_back(cur);
                return;
            }
            for (char ch : {'a', 'b', 'c'}) {
                if (ch != lc) {
                    cur.push_back(ch);
                    func(n, cur, arr, ch);
                    cur.pop_back();
                }
            }
        }
        string getHappyString(int n, int k) {
            vector<string> arr;
            string cur;
            func(n, cur, arr, '\0');
            if (k > arr.size()) {
                return "";
            }
            sort(arr.begin(), arr.end());
            return arr[k - 1];
        }
    };