// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/

class Solution {
    public int maxProductDifference(int[] nums) {
        List<Integer> list = new ArrayList();
        for(int num:nums) {
            list.add(num);
        }
        Collections.sort(list);
        int n= list.size();
        return list.get(n-1)*list.get(n-2)-list.get(0)*list.get(1);
    }
}