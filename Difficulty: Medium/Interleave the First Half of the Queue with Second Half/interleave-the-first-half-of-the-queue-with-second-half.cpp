class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int sz=q.size();
        queue<int>ql,qr;
        for(int i=0;i<sz/2;++i){
            ql.push(q.front());
            q.pop();
            }
            
            while(!q.empty()){
                qr.push(q.front());
                q.pop();
            }
            
            while(!ql.empty()){
                q.push(ql.front());
                ql.pop();
                q.push(qr.front());
                qr.pop();
            }
        
    }
};