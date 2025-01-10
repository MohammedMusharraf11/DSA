class StockSpanner {
public:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> st;

    StockSpanner() {
        // Initialize an empty stack
    }

    int next(int price) {
        int span = 1; // Initialize span for the current price
        
        // Pop elements from the stack while the price on top is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the popped price to the current span
            st.pop();
        }

        // Push the current price and its span onto the stack
        st.push({price, span});

        return span; // Return the calculated span
    }
};
