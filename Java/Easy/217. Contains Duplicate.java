// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set= new HashSet();
        for(var num: nums) {
            set.add(num);
        }
        return nums.length!=set.size();
    }
}