// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        int wordNum = words.size();
        int wordLen = words[0].size();
        int allWordsLen = wordNum * wordLen;
        if (s.size() < allWordsLen) return result;

        std::unordered_map<std::string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            std::unordered_map<std::string, int> windowCounts;

            while (right + wordLen <= s.size()) {
                std::string w = s.substr(right, wordLen);
                right += wordLen;
                if (wordCount.find(w) != wordCount.end()) {
                    windowCounts[w]++;
                    if (windowCounts[w] <= wordCount[w]) 
                        count++;
                    
                    while (count == wordNum) {
                        if (right - left == allWordsLen) {
                            result.push_back(left);
                        }
                        std::string leftWord = s.substr(left, wordLen);
                        left += wordLen;
                        if (wordCount.find(leftWord) != wordCount.end()) {
                            if (windowCounts[leftWord] == wordCount[leftWord]) 
                                count--;
                            windowCounts[leftWord]--;
                        }
                    }
                } else {
                    windowCounts.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};