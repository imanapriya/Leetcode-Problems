1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4      vector<vector<int>> ans;
5        sort(nums.begin(), nums.end());
6        int n = nums.size();
7
8        for (int i = 0; i < n; i++) {
9            if (i > 0 && nums[i] == nums[i - 1]) continue;
10
11            int l = i + 1, r = n - 1;
12            while (l < r) {
13                int sum = nums[i] + nums[l] + nums[r];
14                if (sum == 0) {
15                    ans.push_back({nums[i], nums[l], nums[r]});
16                    l++;
17                    r--;
18                    while (l < r && nums[l] == nums[l - 1]) l++;
19                    while (l < r && nums[r] == nums[r + 1]) r--;
20                } else if (sum < 0) {
21                    l++;
22                } else {
23                    r--;
24                }
25            }
26        }
27        return ans;
28    }
29       
30};