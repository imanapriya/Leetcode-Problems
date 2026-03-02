// User function template for C++
class Solution {
  public:

    vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int m=arr1.size();
        int n=arr2.size();
        int i = m - 1;
        int j = n - 1;
        int carry = 0;
    
    vector<int> ans;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) sum += arr1[i--];
        if (j >= 0) sum += arr2[j--];
        
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    }
};