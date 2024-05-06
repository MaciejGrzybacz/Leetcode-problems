// https://leetcode.com/problems/pass-the-pillow/description/

class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle_length = 2 * n - 2;
        int remaining_time = time % cycle_length; 
        int position=1;
        int direction=1;
        for(int i=1; i<=remaining_time; i++) {
            if(i==n) {
                direction=-1;
            }
            position+=direction;
        }
        return position;
    
    }
};
