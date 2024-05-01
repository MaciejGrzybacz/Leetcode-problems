// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result="";
        while(columnNumber) {
            result+=alphabet[(columnNumber-1)%26];
            columnNumber=(columnNumber-1)/26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};