class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        unordered_set<int> used;
        vector<int> result;

        for (int x : nums1)
            freq[x]++;

        for (int x : nums2) {
            if (freq[x] > 0 && !used.count(x)) {
                result.push_back(x);
                used.insert(x);
            }
        }
        return result;
    }
};
