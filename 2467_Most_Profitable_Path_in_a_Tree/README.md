# 2467. Most Profitable Path in a Tree

## Problem Statement

Given an undirected tree with n nodes (0 to n-1) and a 2D array `edges`, find the maximum net income Alice can obtain. The game rules are:
- Alice starts at node 0, Bob starts at node `bob`
- Each node has a gate with value `amount[i]` (negative for cost, positive for reward)
- Both players move simultaneously each second
- Alice moves towards a leaf node, Bob moves towards node 0
- When players reach a node:
  * If gate is open, no cost/reward
  * If they arrive simultaneously, they share the cost/reward
  * If one arrives first, they get full cost/reward
- Game ends when Alice reaches a leaf or Bob reaches node 0

### Constraints:
- `2 <= n <= 10^5`
- `edges.length == n - 1`
- `1 <= bob < n`
- `amount[i]` is even integer in range `[-10^4, 10^4]`

## Approach

1. **Build Graph and Find Bob's Path:**
   - Create adjacency list from edges
   - Use DFS to find Bob's path to root
   - Store Bob's arrival time at each node

2. **Find Alice's Maximum Profit:**
   - Use DFS from root to find optimal leaf node
   - At each node, calculate profit based on:
     * Who arrives first
     * Whether it's a simultaneous arrival
     * Whether gate is already opened

## Code

```cpp
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> bobPath;
    vector<bool> visited;
    
    bool findBobPath(int node, int parent, vector<int>& path) {
        path.push_back(node);
        
        if (node == 0) {
            return true;
        }
        
        for (int next : graph[node]) {
            if (next != parent) {
                if (findBobPath(next, node, path)) {
                    return true;
                }
            }
        }
        
        path.pop_back();
        return false;
    }
    
    int dfs(int node, int parent, int depth, vector<int>& amount, vector<int>& bobTime) {
        int maxProfit = INT_MIN;
        int currentAmount = amount[node];
        
        if (bobTime[node] == depth) {
            currentAmount /= 2;
        } else if (bobTime[node] > depth || bobTime[node] == -1) {
            currentAmount = amount[node];
        } else {
            currentAmount = 0;
        }
        
        bool isLeaf = true;
        for (int next : graph[node]) {
            if (next != parent) {
                isLeaf = false;
                maxProfit = max(maxProfit, dfs(next, node, depth + 1, amount, bobTime));
            }
        }
        
        if (isLeaf) return currentAmount;
        return currentAmount + maxProfit;
    }
    
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        graph.resize(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> path;
        findBobPath(bob, -1, path);
        bobPath = path;
        
        vector<int> bobTime(n, -1);
        for (int i = 0; i < bobPath.size(); i++) {
            bobTime[bobPath[i]] = i;
        }
        
        return dfs(0, -1, 0, amount, bobTime);
    }
};
```

## Example

**Input:**  
`edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]`

**Output:**  
`6`

**Explanation:**
- Alice starts at 0, Bob at 3
- They open their initial gates (Alice: -2)
- Both reach node 1 simultaneously (Alice: -2 + 4/2 = 0)
- Alice moves to node 4 (Alice: 0 + 6 = 6)
- This is the maximum possible profit

## Complexity Analysis

**Time Complexity:**  
- Building graph and DFS traversals: **O(n)**
- Overall complexity: **O(n)**

**Space Complexity:**  
- Adjacency list and path storage: **O(n)**
- Overall complexity: **O(n)**

## Usage

```cpp
int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    cout << sol.mostProfitablePath(edges, bob, amount) << endl;  // Output: 6
    return 0;
}
```
