// https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
public:
    vector<int> numbers;
    NumArray(vector<int>& nums) {
        numbers=nums;
    }
    
    int sumRange(int left, int right) {
        int result=0;
        for(left; left<=right; left++) {
            result+=numbers[left];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */