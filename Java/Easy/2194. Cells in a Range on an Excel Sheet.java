// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/

class Solution {
    public List<String> cellsInRange(String s) {
        List<String> result = new ArrayList<>();
        String[] parts = s.split(":");
        int startCol = parts[0].charAt(0) - 'A' + 1, endCol = parts[1].charAt(0) - 'A' + 1;
        int startRow = Integer.parseInt(parts[0].substring(1)), endRow = Integer.parseInt(parts[1].substring(1));
        
        for (int c = startCol; c <= endCol; c++) {
            for (int r = startRow; r <= endRow; r++) {
                result.add((char) ('A' + c - 1) + "" + r);
            }
        }
        
        return result;
    }
}