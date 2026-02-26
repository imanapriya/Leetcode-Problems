class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>ans;
        queue<int>q;
        q.push(0);
        
        bitset<10001>vis;
        
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            
            if(vis[nd]){
                continue;
            }
            vis[nd]=1;
            
            ans.push_back(nd);
            for(int& child:adj[nd]){
                q.push(child);
            }
        }
        return ans;
    }
};