// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),  [](int a, int b) {return a > b;});
        long long result=0;
        for(int i=0; i<k; i++) {
            if(happiness[i]<=i) {
                break;
            }
            result+=happiness[i]-i;
        }
        return result;

    }
};