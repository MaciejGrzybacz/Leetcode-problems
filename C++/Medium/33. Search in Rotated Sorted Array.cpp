// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int find_pivot(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    int binary_search(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = find_pivot(nums);
        int n = nums.size();
        
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binary_search(nums, target, pivot, n - 1);
        } else {
            return binary_search(nums, target, 0, pivot - 1);
        }
    }
};
