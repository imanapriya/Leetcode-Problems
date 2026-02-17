class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < 32; i++) {
            int ones = 0;

            for(int j = 0; j < n; j++) {
                if((nums[j] >> i) & 1) {
                    ones++;
                }
            }

            int zeros = n - ones;
            total += ones * zeros;
        }

        return total;
        }
};