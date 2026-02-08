class Solution {
public:
    bool isBalanced(string num) {
        int odd=0,even=0;
        for(int i=0;i<num.size();i+=2){
            even=even+num[i] - '0';
        }
         for(int i=1;i<num.size();i+=2){
                odd=odd+num[i] - '0';
            
            }
         return even==odd;
        
    }
};