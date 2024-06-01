// https://leetcode.com/problems/unique-number-of-occurrences/description/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        set<int> my_set;

        for(int i : arr) {
            if(map.find(i) != map.end()) {
                map[i] = map[i] + 1;
            } else {
                map[i] = 1;
            }
        }

        for(const auto &pair : map) {
            my_set.insert(pair.second);
        }
        
        return map.size() == my_set.size();
    }
};