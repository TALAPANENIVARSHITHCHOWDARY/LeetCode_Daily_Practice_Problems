#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
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
