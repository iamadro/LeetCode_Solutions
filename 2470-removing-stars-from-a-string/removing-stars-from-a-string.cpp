class Solution {
public:
    string removeStars(string s) {
        stack<char> chars;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!chars.empty()) chars.pop();
            } else {
                chars.push(s[i]);
            }
        }

        s = "";
        stack<char> rev;
        while (!chars.empty()) {
            rev.push(chars.top());
            chars.pop();
        }

        while (!rev.empty()) {
            s += rev.top();
            rev.pop();
        }

        return s;

    }
};