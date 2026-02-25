#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }
        
        // Step 3: Gather top k frequent elements
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};