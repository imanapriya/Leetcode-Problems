class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currents=nums[0];
        int maxs=nums[0];
        for(int i=1;i<n;i++){
            currents=max(nums[i],currents+nums[i]);
            maxs=max(maxs,currents);
        }
        return maxs;
    }
};