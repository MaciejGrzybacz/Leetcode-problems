// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/description/

package Java.Easy;

class Solution {
    private boolean checkIfNum(String s) {
        for(int i=0; i<s.length(); i++) {
            if (s.charAt(i) < '0'
                    || s.charAt(i) > '9') {
                return false;
            }
        }
        return true;
    }
    public boolean areNumbersAscending(String s) {
        var strings = s.split(" ");
        Integer max_int=0;
        for(var str : strings) {
            if(checkIfNum(str)) {
                Integer curr_int=Integer.valueOf(str);
                if(curr_int<=max_int) {
                    return false;
                }
                else {
                    max_int=curr_int;
                }

            }
        }
        return true;
    }

}
