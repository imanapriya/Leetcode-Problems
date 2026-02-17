class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int sz = arr.size();
        stack<int> st;

        for(int i = 0; i < sz; ++i) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && arr[i] < 0) {
                if(abs(arr[i]) > st.top()) {
                    st.pop();
                }
                else if(abs(arr[i]) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(arr[i]);
            }
        }

        vector<int> ans(st.size());
        
        for(int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
