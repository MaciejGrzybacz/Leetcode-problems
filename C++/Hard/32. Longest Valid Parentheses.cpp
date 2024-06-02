// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> my_stack;
        int result = 0;
        my_stack.push(-1);
        for(int i = 0; i< s.size(); i++) {
            if(s[i] == '('){
                my_stack.push(i);
            } else {
                my_stack.pop();
                if(my_stack.empty()) {
                    my_stack.push(i);
                } else {
                    result=max(result, i - my_stack.top());
                }
            }
        }
        return result;
    }
};