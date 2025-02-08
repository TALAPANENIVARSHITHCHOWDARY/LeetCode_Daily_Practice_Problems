# 2349. Design a Number Container System

## Problem Statement

Design a system that allows efficiently storing numbers at different indices and retrieving the smallest index for a given number.

Implement the `NumberContainers` class:

- `NumberContainers()` Initializes the object.
- `void change(int index, int number)`: Stores the number at the given index. If the index already contains a number, it is replaced.
- `int find(int number)`: Returns the smallest index associated with the given number, or `-1` if no such index exists.

### Constraints:
- `1 <= index, number <= 10^9`
- At most `10^5` calls to `change` and `find`.

## Approach

1. **Use Two Hash Maps:**
   - `indexToNumber`: Maps each index to its assigned number.
   - `numberToIndices`: Maps each number to a sorted set of indices.
   
2. **Efficient Index Management:**
   - When a number at an index is updated, remove the old number from `numberToIndices`.
   - Insert the new number and update the smallest index retrieval.

## Code

```cpp
class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```

## Example

**Input:**
```cpp
NumberContainers nc;
nc.change(1, 10);
nc.change(2, 10);
nc.change(3, 20);
nc.find(10);
nc.find(20);
nc.change(2, 30);
nc.find(10);
```

**Output:**
```cpp
1
3
1
```

**Explanation:**
1. `change(1, 10)`: Stores `10` at index `1`.
2. `change(2, 10)`: Stores `10` at index `2`.
3. `change(3, 20)`: Stores `20` at index `3`.
4. `find(10)`: Returns the smallest index with `10`, which is `1`.
5. `find(20)`: Returns `3`.
6. `change(2, 30)`: Changes index `2` from `10` to `30`.
7. `find(10)`: Now returns `1` as `2` is no longer mapped to `10`.

## Complexity Analysis

**Time Complexity:**
- `change()`: **O(log n)** due to insertion and deletion in `set`.
- `find()`: **O(1)** for retrieving the smallest index.
- Overall complexity: **O(n log n)**.

**Space Complexity:**
- **O(n)** for storing mappings in hash maps.

## Usage

```cpp
int main() {
    NumberContainers nc;
    nc.change(1, 10);
    nc.change(2, 10);
    nc.change(3, 20);
    cout << nc.find(10) << endl; // Output: 1
    cout << nc.find(20) << endl; // Output: 3
    nc.change(2, 30);
    cout << nc.find(10) << endl; // Output: 1
    return 0;
}
```

