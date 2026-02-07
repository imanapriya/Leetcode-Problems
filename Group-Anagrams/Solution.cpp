1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4         unordered_map<string, vector<string>> mp;
5
6        for (int i = 0; i < strs.size(); i++) {
7            string temp = strs[i];
8            sort(temp.begin(), temp.end());
9            mp[temp].push_back(strs[i]);
10        }
11
12        vector<vector<string>> result;
13
14        for (auto it : mp) {
15            result.push_back(it.second);
16        }
17
18        return result;
19    }
20        
21    
22};