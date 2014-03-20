// Given n non-negative integers representing the histogram's bar height 
// where the width of each bar is 1, 
// find the area of largest rectangle in the histogram.

// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

class Solution {
public:
    // O(N)
    int largestRectangleArea(vector<int> &h) {
        stack<int> s;
        h.push_back(0); // mark the end
        int i = 0, maxRec = 0;
        while (i < h.size()) {
            if (s.empty() || h[s.top()] <= h[i]) {
                s.push(i); // store the indexes of ascending order by now.
                i++;
            }
            else {
                int t = s.top();
                s.pop(); 
                // Note: the smaller item is the bottle neck.
                // while h[i] is less than the top of stack, pop it out, then 
                // keep calculating rectangles that start with the h[new_top] 
                // and end before h[i], (since items between new_top and top
                // must be greater than h[top]) utill h[i] is bigger than the 
                // new top of stack, then push it in.
                // when reach the end of h, since 0 is smaller than any item in
                // the stack, all rectangle areas will be computed backwards.
                maxRec = max(maxRec, h[t] * (s.empty() ? i : i-s.top()-1));
            }
        }
        return maxRec;
    }
};

// O(N^2), cannot pass the large test set
int largestRectangleArea(vector<int> &height) {
    int size = height.size();
    int h, left, right;
    int maxRec = 0;
    for (int i = 0; i < size; i++) {
        h = height[i];
        for (left = i; left >= 0; left--) {
            if (height[left] < h)
                break;
        }
        left++;
        for (right = i; right < size; right++) {
            if (height[right] < h)
                break;
        }
        right--;
        maxRec = max(maxRec, h * (right-left+1));
    }
    return maxRec;
}
