class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        
        vector<int> temp(n);
        
        for(int i = 0; i < n; i++) {
            temp[i] = arr[(i + d) % n];
        }
        
        arr = temp;
    }
};