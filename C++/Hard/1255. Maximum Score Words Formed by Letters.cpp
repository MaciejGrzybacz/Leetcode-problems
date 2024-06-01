// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

class Solution {
private:
    unordered_map<string, int> scores;

    int calculate_word_score(const string& s, const vector<int>& score) {
        int result = 0;
        for (char ch : s) {
            result += score[ch - 'a'];
        }
        return result;
    }

    int backtracking(vector<string>& words, unordered_map<char, int>& available, int index) {
        if (index == words.size()) {
            return 0;
        }

        int max_score = backtracking(words, available, index + 1);

        string current_word = words[index];
        unordered_map<char, int> temp_counts = available;
        bool can_include = true;
        
        for (char ch : current_word) {
            if (temp_counts[ch] < 1) {
                can_include = false;
                break;
            }
            temp_counts[ch]--;
        }

        if (can_include) {
            max_score = max(max_score, scores[current_word] + backtracking(words, temp_counts, index + 1));
        }

        return max_score;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> counts;
        for (char letter : letters) {
            counts[letter]++;
        }

        for (const string& word : words) {
            scores[word] = calculate_word_score(word, score);
        }

        return backtracking(words, counts, 0);
    }
};