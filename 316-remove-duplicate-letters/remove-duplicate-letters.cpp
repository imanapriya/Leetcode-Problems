class Solution {
public:
    string removeDuplicateLetters(string s) {
        int sz = s.size();
        
        vector<int> mp(26, 0);
        vector<bool> inStack(26, false);
        
        for(char &ch : s){
            ++mp[ch - 'a'];
        }
        
        stack<char> st;
        
        for(int i = 0; i < sz; ++i){
            char ch = s[i];
            mp[ch - 'a']--;
            
            if(inStack[ch - 'a'])
                continue;
            
            while(!st.empty() && 
                  ch < st.top() && 
                  mp[st.top() - 'a'] > 0){
                
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(ch);
            inStack[ch - 'a'] = true;
        }
        
        string ans(st.size(), ' ');
        for(int i = st.size() - 1; i >= 0; --i){
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};
