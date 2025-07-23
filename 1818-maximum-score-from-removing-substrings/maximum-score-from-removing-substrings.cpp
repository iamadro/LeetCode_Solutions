class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first, second;
        int first_score, second_score;
        
        // Determine which operation to perform first
        if (x > y) {
            first = "ab";
            second = "ba";
            first_score = x;
            second_score = y;
        } else {
            first = "ba";
            second = "ab";
            first_score = y;
            second_score = x;
        }
        
        int total = 0;
        
        // Perform first operation
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == first[0] && c == first[1]) {
                st.pop();
                total += first_score;
            } else {
                st.push(c);
            }
        }
        
        // Perform second operation on the remaining string
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        for (char c : remaining) {
            if (!st.empty() && st.top() == second[0] && c == second[1]) {
                st.pop();
                total += second_score;
            } else {
                st.push(c);
            }
        }
        
        return total;
    }
};