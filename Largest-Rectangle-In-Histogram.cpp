class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int maxArea = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < heights.size(); i++) {
            int value = i;
            while(!s.empty() && heights[i] < s.top().second) {
                auto [index, height] = s.top();
                s.pop();
                int area = height * (i - index);
                if(area > maxArea) maxArea = area;
                value = index;
            }
            s.push({value, heights[i]});
        }
        return maxArea;
    }
};