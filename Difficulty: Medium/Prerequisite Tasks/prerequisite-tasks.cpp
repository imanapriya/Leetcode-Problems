class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(N);
        for(auto &pr : prerequisites) {
            adj[pr.second].push_back(pr.first);
        }
        
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++) {
            for(auto &neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto &neighbour : adj[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        return count == N;
    }
};