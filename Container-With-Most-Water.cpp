class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int area = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l <= r) {
            if(height[l] <= height[r]) {
                area = height[l] * (r - l);
                if(area > max_area) max_area = area;
                l++;
            }
            else {
                area = height[r] * (r - l);
                if(area > max_area) max_area = area;
                r--;
            }
        }
        return max_area;
    }
};