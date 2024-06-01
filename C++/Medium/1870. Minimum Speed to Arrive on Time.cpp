// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

class Solution {
public:
    bool calculateArrivalTime(vector<int>& dist, double speed, double hour) {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; ++i) {
            time += ceil((double)dist[i] / speed);
        }
        time += (double)dist.back() / speed;
        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        double right = INT_MAX;
        while (left < right) {
            double mid = left + (right - left) / 2;
            if (calculateArrivalTime(dist, mid, hour)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left == INT_MAX ? -1 : left;
    }
};