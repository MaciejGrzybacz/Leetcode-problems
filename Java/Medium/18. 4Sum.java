// https://leetcode.com/problems/4sum/description/

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Set<List<Integer>> result = new HashSet<>();
        Arrays.sort(nums);
        long targetLong = target;
        for (int i = 0; i < nums.length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                List<List<Integer>> twoSumPairs = twoSum(nums, j + 1, nums.length - 1, targetLong - nums[i] - nums[j]);
                for (List<Integer> pair : twoSumPairs) {
                    List<Integer> quad = new ArrayList<>(Arrays.asList(nums[i], nums[j]));
                    quad.addAll(pair);
                    result.add(quad);
                }
            }
        }
        return new ArrayList<>(result);
    }

    private List<List<Integer>> twoSum(int[] nums, int left, int right, long target) {
        List<List<Integer>> pairs = new ArrayList<>();
        while (left < right) {
            long sum = nums[left] + nums[right]; 
            if (sum == target) {
                pairs.add(Arrays.asList(nums[left], nums[right]));
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++; 
                while (left < right && nums[right] == nums[right + 1]) right--; 
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return pairs;
    }
}