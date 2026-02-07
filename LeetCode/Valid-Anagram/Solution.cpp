1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if(s.length()!=t.length()){
5            return false;
6        }
7        sort(s.begin(),s.end());
8        sort(t.begin(),t.end());
9        return s==t;
10        
11        
12    }
13};