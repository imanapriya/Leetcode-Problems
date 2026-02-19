class Solution {
public:
    int count = 0;
    unordered_map<int,int> freq;

    void solve(vector<int>& nums, int k, int index) {
        if(index == nums.size()) {
            count++;
            return;
        }

        // Skip
        solve(nums, k, index + 1);

        // Include (if valid)
        if(freq[nums[index] - k] == 0) {
            freq[nums[index]]++;
            solve(nums, k, index + 1);
            freq[nums[index]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // 🔥 IMPORTANT
        solve(nums, k, 0);
        return count - 1;  // remove empty subset
    }
};
