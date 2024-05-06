// https://leetcode.com/problems/happy-number/description/

class Solution {
    public int squaredSum(int n) {
        int result=0;
        while(n>0){
            result+=(n%10)*(n%10);
            n/=10;
        }
        return result;
    }
    public boolean isHappy(int n) {
        Set<Integer> results=new HashSet();
        while(n>1) {
            results.add(n);
            n=squaredSum(n);
            if(results.contains(n)) {
                return false;
            }
        }
        return true;
    }
}