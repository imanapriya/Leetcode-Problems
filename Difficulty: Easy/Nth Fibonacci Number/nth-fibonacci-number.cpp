class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n==0) return 0; 
        if (n==1) return 1; 
        int ans=nthFibonacci(n-1)+nthFibonacci(n-2); 
        return ans;
    }
};