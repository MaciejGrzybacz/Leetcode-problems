// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result_sum=0;
        for(int num: nums) {
            result_sum+=num;
        }
        return (nums.size()+1)*(nums.size())/2-result_sum;
    }
};
