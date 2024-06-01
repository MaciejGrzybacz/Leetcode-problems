// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/

class Solution {
public:
    int countWords(string str) {
        int word_count=1;
        for(auto c: str) {
            if(c==' ') {
                word_count++;
            }
        }
        return word_count;
    }
    int mostWordsFound(vector<string>& sentences) {
        int max_word_count=0;
        for(auto sentence: sentences) {
            max_word_count=max(max_word_count,countWords(sentence));
        }
        return max_word_count;
    }
};