class Solution {
public:
    int minimumDeletions(string s) {
        int bcount=0;
        int d=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                bcount++;
            }
            else{
                d=min(d+1,bcount);
            }
        }
        return d;
        
    }
};