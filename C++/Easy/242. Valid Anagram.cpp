// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0);
        for(char c:s){
            vec[c-'a']++;
        }
        for(char c: t) {
            vec[c-'a']--;
        }
        for(int occ : vec) {
            if (occ!=0) {
                return false;
            }
        }
        return true;
    }
};
