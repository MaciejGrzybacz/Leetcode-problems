// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

class Solution {
    public int findMaxK(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        if(nums.length==0) {
            return -1;
        }
        for(var num: nums) {
            set.add(num);
        }
        int max_num=-1;
        for(var num: nums) {
            if(num>max_num && set.contains(-num)) {
                max_num=num;
            }
        }
        return max_num;
    }
}