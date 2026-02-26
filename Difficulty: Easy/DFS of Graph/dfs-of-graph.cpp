class Solution {
  public:
  
    void dfsHelper(int node, vector<vector<int>>& adj, 
                   vector<int>& ans, vector<bool>& visited) {
        
        visited[node] = true;
        ans.push_back(node);
        
        for(auto neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfsHelper(neighbour, adj, ans, visited);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        
        dfsHelper(0, adj, ans, visited);  // Start from 0
        
        return ans;
    }
};