#include<bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    private:
        vector<int> prefixArr;
    public:
        ProductOfNumbers() {
            prefixArr = {1};
        }
        void add(int num) {
            if (num == 0) {
                prefixArr = {1};
            } else {
                prefixArr.push_back(prefixArr.back() * num);
            }
        }
        
        int getProduct(int k) {
            int n = prefixArr.size();
            if (k >= n) {
                return 0;
            }
            return prefixArr.back() / prefixArr[n - 1 - k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */