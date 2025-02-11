#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            stack<char> st;
            int sLen = s.length();
            int pLen = part.length();
            for (int i = 0; i < sLen; i++) {
                st.push(s[i]);
                if (st.size() >= pLen && match(st, part, pLen)) {
                    for (int j = 0; j < pLen; j++) {
                        st.pop();
                    }
                }
            }
            string result = "";
            while (!st.empty()) {
                result = st.top() + result;
                st.pop();
            }
            return result;
        }
    
    private:
        bool match(stack<char>& st, string& part, int pLen) {
            stack<char> temp = st;
            for (int i = pLen - 1; i >= 0; i--) {
                if (temp.top() != part[i]) {
                    return false;
                }
                temp.pop();
            }
            return true;
        }
    };