class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int dif=x^y;
        for(int i=31;i>=0;--i){
            if((dif>>i)&1){
                count++;
            }
        }
        return count;
    }
};