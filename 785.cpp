class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        vector<int> color(nodeCount, 0);
        queue<int> nodesQueue;

        for (int node = 0; node < nodeCount; ++node) {
            if (color[node] != 0) continue;

            nodesQueue.push(node);
            color[node] = 1;

            while (!nodesQueue.empty()) {
                int current = nodesQueue.front();
                nodesQueue.pop();

                for (int neighbor : graph[current]) {
                    if (color[neighbor] != 0) {
                        if (color[neighbor] == color[current]) return false;
                    } else {
                        color[neighbor] = -color[current];
                        nodesQueue.push(neighbor);
                    }
                }
            }
        }
        return true;
    }
};
