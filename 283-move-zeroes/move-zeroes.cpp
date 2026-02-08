class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertpos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insertpos++] = nums[i];
            }
        }

        for (int i = insertpos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
