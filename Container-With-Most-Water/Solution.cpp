1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int left = 0;
5        int right = height.size() - 1;
6        int maxArea = 0;
7
8        while (left < right) {
9            int area = min(height[left], height[right]) * (right - left);
10            maxArea = max(maxArea, area);
11
12            if (height[left] < height[right]) {
13                left++;
14            } else {
15                right--;
16            }
17        }
18
19        return maxArea;
20    }
21};
22