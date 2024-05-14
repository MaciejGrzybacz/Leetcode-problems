// https://leetcode.com/problems/tuple-with-same-product/description/

class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> map = new HashMap();
        for(int i=0; i<nums.length; i++) {
            for(int j=i+1; j<nums.length; j++) {
                int key=nums[i]*nums[j];
                if(!map.containsKey(key)) {
                    map.put(key,1);
                } else {
                    map.put(key, map.get(key)+1);
                }
            }
        }
        int tupleCount=0;
        for (int count : map.values()) {
            if (count > 1) {
                tupleCount += (count * (count - 1) / 2) * 8; 
            }
        }
        return tupleCount;
    }
}