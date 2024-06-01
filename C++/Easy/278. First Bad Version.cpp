// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int m = left + (right - left) / 2;
            if (isBadVersion(m)) {
                right = m;
            } else {
                left = m + 1;
            }
        }
        return left;
    }
};