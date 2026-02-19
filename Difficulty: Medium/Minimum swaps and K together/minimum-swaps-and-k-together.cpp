// Final function implementation
class Solution {
  public:
    int f(vector<int>& nums, int &k) {
        int swaps = 0, cntLess = 0;
        for(int &num : nums) if(num <= k) cntLess += 1;
        for(int i=0; i<nums.size() and cntLess; ++i) {
            if(nums[i] <= k) cntLess -= 1;
            else swaps += 1, cntLess -= 1;
        }
        return swaps;
    }
    int minSwap(vector<int>& nums, int k) {
        // code here
        int a = f(nums, k);
        reverse(begin(nums), end(nums));
        int b = f(nums, k);
        return  min(a, b);
    }
};