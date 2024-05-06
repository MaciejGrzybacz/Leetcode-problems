// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long result=0;
        if(cost1>cost2) { //cost2 must be bigger or equal cost2 to make algorithm more optimal
            swap(cost1,cost2);
        }
        for(size_t i=0; i<=total; i+=cost2) {
            result+=((total-i)/cost1+1);
        }
        return result;
    }
};