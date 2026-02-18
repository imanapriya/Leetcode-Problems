class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  

        long long result = 0;

        for (int i = 0; i < n; i++) {
            int low = lower - nums[i];
            int high = upper - nums[i];

            
            int left = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();

            
            int right = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();

            result += (right - left);
        }

        return result;
    }
};
