class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(N);
        
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> indegree(N, 0);
        
        for(int i = 0; i < N; i++) {
            for(auto &nbr : adj[i]) {
                indegree[nbr]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto &nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        return count == N;
    }
};