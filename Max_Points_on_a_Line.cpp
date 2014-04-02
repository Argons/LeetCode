// Given n points on a 2D plane, find the maximum number of points 
// that lie on the same straight line.

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float, int> mp;
        int maxNum = 0;
        for (int i = 0; i < points.size(); i++) {
            mp.clear();
            mp[INT_MIN] = 0; // axis y
            int duplicate = 1;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) 
                    continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                float k = points[i].x == points[j].x ? INT_MAX : (float)\
                    (points[j].y - points[i].y) / (points[j].x - points[i].x);
                mp[k]++;
            }
            unordered_map<float, int>::iterator it = mp.begin();
            for (; it != mp.end(); it++) {
                if (it->second + duplicate > maxNum) {
                    maxNum = it->second + duplicate;
                }
            }
        }
        return maxNum;
    }
};
