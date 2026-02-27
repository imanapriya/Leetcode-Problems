
  class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        // Step 2: Compute indegree
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }
        
        // Step 3: Kahn's Algorithm
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto neighbour : adj[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        return topo;
    }
};