class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size();
        int sz2=nums2.size();
        stack<int> st;
        vector<int> nge(10001,-1);
        for(int i=0;i<sz2;++i){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                int ind=st.top();
                st.pop();
                int ele=nums2[ind];
                nge[ele]=nums2[i];
                
            }
            st.push(i);
        }
        vector<int>ans(sz1,-1);
        
        for(int i=0;i<sz1;++i){
            int queryk=nums1[i];
            ans[i]=nge[queryk];
        }
        return ans;
    }
};