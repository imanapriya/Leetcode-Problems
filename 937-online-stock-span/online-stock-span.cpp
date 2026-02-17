class StockSpanner {
public:
    int day;
    stack<array<int,2>>st;
    StockSpanner() {
        day=0;
    }
    
    int next(int price) {
        ++day;

        while(!st.empty() && st.top()[0]<=price){
            st.pop();
        }
        int ans=day- (st.empty() ? 0:st.top()[1]);
        st.push({price,day});
        return ans;

    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */