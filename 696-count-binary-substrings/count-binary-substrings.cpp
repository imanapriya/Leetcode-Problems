class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,curr=1,result=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
              result+=min(curr,prev);
              prev=curr;
              curr=1;//new character in index i
            }
        }
        return result+min(curr,prev); //loop theke beriye asar por jeta thakbe seta add hoye jbe
    }
};