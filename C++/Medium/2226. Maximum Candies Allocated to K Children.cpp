// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

class Solution {
public:
    bool canDivide(vector<int>& candies, long long k, int c) {
        if (c == 0) return false; 
        for (int candie : candies) {
            k -= (long long)candie / c;
            if (k <= 0) {
                break;
            }
        }
        return k <= 0;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0;
        long long right = LLONG_MAX;
        while (left < right) {
            long long m = left + (right - left) / 2;
            if (canDivide(candies, k, m)) {
                left = m + 1;
            } else {
                right = m;
            }
        }
        return max(left - 1,0); 
    }
};
