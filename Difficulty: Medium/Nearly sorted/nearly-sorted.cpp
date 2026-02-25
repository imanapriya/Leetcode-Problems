class Solution {
public:
    vector<int> nearlySorted(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        
        // Push first k+1 elements
        for(int i = 0; i < n && i <= k; i++) {
            pq.push(arr[i]);
        }
        
        int index = 0;
        
        // Process remaining elements
        for(int i = k + 1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            
            pq.push(arr[i]);
        }
        
        // Empty remaining heap
        while(!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
        
        return arr;
    }
};