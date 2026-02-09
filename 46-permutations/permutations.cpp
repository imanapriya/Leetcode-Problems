class Solution {
public:
    int sz;
    vector<vector<int>> ans;

    void func(vector<int>& nums, int ind) {
        if (ind >= sz) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < sz; ++i) {
            swap(nums[ind], nums[i]);
            func(nums, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        ans.clear();
        func(nums, 0);
        return ans;
    }
};
