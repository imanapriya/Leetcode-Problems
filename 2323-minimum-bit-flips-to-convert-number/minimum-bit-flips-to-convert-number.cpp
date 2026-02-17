class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip=start^goal;
        int count=0;
        for(int i=31;i>=0;--i){
            if((flip>>i)&1){
                count++;            }
        }
        return count;
    }
};