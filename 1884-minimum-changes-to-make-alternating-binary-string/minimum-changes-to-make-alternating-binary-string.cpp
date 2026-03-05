class Solution {
public:
    int minOperations(string s) {
        int start0=0,start1=0;
        
        for(int i=0;i<s.size();i++){
            char expect0=(i%2==0) ? '0':'1';
            if(s[i]!=expect0) start0++;

            char expect1=(i%2==0) ? '1':'0';
            if(s[i]!=expect1) start1++;
        }

        return min(start0,start1);
    }
};