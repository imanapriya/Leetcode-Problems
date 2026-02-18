class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size(),index=0;
        sort(nums.begin(),nums.end());
        int mid=(n+1)/2;
        for(;mid<n;mid++){
            if(2*nums[index]<=nums[mid]){
                index++;
                
            }
        }
        int ans=2*index;
        return ans;
    }
};