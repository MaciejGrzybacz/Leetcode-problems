// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void generatePartitions(const string& s, vector<string>& current, int index, vector<vector<string>>& result) {
        if (index == s.length()) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            std::string sub = s.substr(index, i - index + 1);
            if (isPalindrome(sub)) {
                current.push_back(sub);  
                generatePartitions(s, current, i + 1, result);
                current.pop_back(); 
            }
        }
    }

    vector<vector<std::string>> partition(const string& s) {
        vector<vector<string>> result;
        vector<string> current;
        generatePartitions(s, current, 0, result);
        return result;
    }
};