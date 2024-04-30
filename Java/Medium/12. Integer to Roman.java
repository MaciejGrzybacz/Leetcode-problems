// https://leetcode.com/problems/integer-to-roman/description/

class Solution {
    public String intToRoman(int num) {
        HashMap<Integer,String> dict=new HashMap();
        dict.put(1000, "M");
        dict.put(900, "CM");
        dict.put(500, "D");
        dict.put(400, "CD");
        dict.put(100, "C");
        dict.put(90, "XC");
        dict.put(50, "L");
        dict.put(40, "XL");
        dict.put(10, "X");
        dict.put(9, "IX");
        dict.put(5, "V");
        dict.put(4, "IV");
        dict.put(1, "I");

        Integer[] keys = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder result = new StringBuilder();
        while(num > 0) {
            int i = 0;
            while (keys[i] > num) {
                i++;
            }
            result.append(dict.get(keys[i]));
            num -= keys[i];
        }
        return result.toString();
    }
}
