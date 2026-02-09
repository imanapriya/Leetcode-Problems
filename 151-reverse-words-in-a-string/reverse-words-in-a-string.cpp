class Solution {
public:
    string reverseWords(string &s) {
        int sz = s.size();
        vector<string> ans;
        string word;

        int i = 0;
        while (i < sz && s[i] == ' ') ++i;

        for (; i < sz; ++i) {
            if (s[i] == ' ') {
                if (i > 0 && s[i - 1] == ' ') {
                    continue;
                }
                ans.push_back(word);
                word.clear();
            } else {
                word.push_back(s[i]);
            }
        }

        if (!word.empty()) {
            ans.push_back(word);
        }

        string str;
        for (int i = ans.size() - 1; i >= 0; --i) {
            str += ans[i];
            if (i > 0) {
                str.push_back(' ');
            }
        }

        return str;
    }
};
