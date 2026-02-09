class Solution {
public:
    int fib(int n) {
       if(n<=1) return n;
        int a=0,b=1;
        for(int i=1;i<n;i++){
            int n2=a+b;
            a=b;
            b=n2;            
        }
        return b;

    }
};