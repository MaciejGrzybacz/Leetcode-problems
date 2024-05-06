// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<min((i+k+1),int(nums.size())); j++) {
                if(nums[i]==nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
