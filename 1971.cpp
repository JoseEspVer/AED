#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        stack<int> s;
        unordered_set<int> visited; 
        s.push(source); 
        visited.insert(source);
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (current == destination) {
                return true;
            }
            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return false;
    }
};