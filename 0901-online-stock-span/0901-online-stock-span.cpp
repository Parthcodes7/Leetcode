class StockSpanner {
    stack<pair<int, int>> st; // stores {price, index}
    int ind;

public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        int span = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        
        return span;
    }
};