class Solution {
public:
    int minPartitions(string n) {
        //return *max_element(n.begin(), n.end()) - '0';
        int result=0;
        for(char c:n){
        result=max(result,c - '0');
        }
        return result;
    } 
};