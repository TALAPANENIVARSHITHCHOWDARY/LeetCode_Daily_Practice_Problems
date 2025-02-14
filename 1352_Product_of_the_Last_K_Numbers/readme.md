# 1352. Product of the Last K Numbers

## Problem Statement

Implement a class `ProductOfNumbers` that supports the following operations:

- `add(int num)`: Adds `num` to the list of numbers.
- `getProduct(int k)`: Returns the product of the last `k` numbers in the list.

If any of the last `k` numbers is `0`, the product is `0`.

### Constraints:
- `1 <= num <= 100`
- `1 <= k <= number of elements in the list`

## Approach

1. **Use a Prefix Product Array:**
   - Maintain a prefix product array `prefixArr` initialized with `1`.
   - On adding a number:
     - If it's `0`, reset the array to `{1}`.
     - Otherwise, append the product of the last element and the new number.
   
2. **Querying the Product Efficiently:**
   - Use the formula `prefixArr.back() / prefixArr[n - 1 - k]` to compute the product efficiently.
   - If `k` exceeds the current array size, return `0`.

## Code

```cpp
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
```

## Example

**Input:**
```cpp
ProductOfNumbers productOfNumbers;
productOfNumbers.add(3);
productOfNumbers.add(0);
productOfNumbers.add(2);
productOfNumbers.add(5);
productOfNumbers.add(4);
cout << productOfNumbers.getProduct(2) << endl;
cout << productOfNumbers.getProduct(3) << endl;
cout << productOfNumbers.getProduct(4) << endl;
```

**Output:**
```cpp
20
40
0
```

**Explanation:**
- `getProduct(2)`: Last two numbers are `[5, 4]`, product is `20`.
- `getProduct(3)`: Last three numbers are `[2, 5, 4]`, product is `40`.
- `getProduct(4)`: Last four numbers include `0`, so the result is `0`.

## Complexity Analysis

**Time Complexity:**
- `add(num)`: **O(1)** since it updates the last prefix product.
- `getProduct(k)`: **O(1)** using division.

**Space Complexity:**
- **O(n)** where `n` is the number of elements added (in worst case, if no zeros are encountered).

## Usage

```cpp
int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    cout << productOfNumbers.getProduct(2) << endl; // Output: 20
    cout << productOfNumbers.getProduct(3) << endl; // Output: 40
    cout << productOfNumbers.getProduct(4) << endl; // Output: 0
    return 0;
}
```



