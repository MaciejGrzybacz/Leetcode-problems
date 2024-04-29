// https://leetcode.com/problems/reverse-integer/description/

#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int sign= (x<0) ? -1 : 1;
        x=abs(x);
        int int_max=pow(2,31)-1;
        int result=0;
        while(x>0){
            if(result<int_max/10.0){
                result*=10;
                result+=x%10;
                x/=10;
            }
            else {
                return 0;
            }
        }
        return sign*result;
    }
};
