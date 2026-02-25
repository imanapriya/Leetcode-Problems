class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int &it : arr){
            pq.push(it);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> result;
        
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        // Optional: reverse to get descending order
        reverse(result.begin(), result.end());
        
        return result;
    }
};