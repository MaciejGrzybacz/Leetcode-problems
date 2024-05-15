// https://leetcode.com/problems/count-asterisks/description/

class Solution {
    public int countAsterisks(String s) {
        boolean closed=true;
        int starCount=0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='*' && closed){
                starCount++;
            }
            if(s.charAt(i)=='|') {
                closed = !closed;
            }
        }
        return starCount;
    }
}