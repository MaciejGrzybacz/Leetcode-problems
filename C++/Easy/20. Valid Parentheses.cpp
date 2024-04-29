// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(auto c: s) {
            if (c=='(' || c=='[' || c=='{') {
                st.push(c);
            }
            else {
                switch(c) {
                    case ')':
                        if (st.empty() || st.top() != '(') {
                            return false;
                        }
                        st.pop();
                        break;
                    case ']':
                        if (st.empty() || st.top() != '[') {
                            return false;
                        }
                        st.pop();
                        break;
                    case '}':
                        if (st.empty() || st.top() != '{') {
                            return false;
                        }
                        st.pop();
                        break;
                }
            }
        }
        return st.empty();
    }
};
