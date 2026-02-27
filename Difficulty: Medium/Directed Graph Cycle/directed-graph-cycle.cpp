class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& pathVisited) {
        
        visited[node] = true;
        pathVisited[node] = true;
        
        for(auto neighbour : adj[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, adj, visited, pathVisited))
                    return true;
            }
            else if(pathVisited[neighbour]) {
                return true;   // cycle found
            }
        }
        
        pathVisited[node] = false;  // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        
        // Step 1: Convert edges to adjacency list
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        
        // Step 2: Check each component
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }
        
        return false;
    }
};