// Given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two end 
// points of line i is at (i, ai) and (i, 0). Find two lines, which together 
// with x-axis forms a container, such that container contains the most water.

// Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;  
        int end = height.size() - 1;  
        int maxVol = 0;  
        while (start < end) {
            int contain = min(height[end], height[start]) * (end-start);  
            maxVol = max(maxVol, contain); 
            if (height[start] <= height[end])
                start++;  
            else
                end--;
        }  
        return maxVol;     
    }
};
