class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
         priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int x : arr)
            pq.push(x);
        
        int cost = 0;
        
        while(pq.size() > 1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            int sum = first + second;
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
    }
};