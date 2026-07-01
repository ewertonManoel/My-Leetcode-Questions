class Solution {
private:
    vector<int> seg;
    int build(int p, int l, int r, vector<int>& heights) {
        if(l == r) return seg[p] = heights[l];
        int mid = l + (r - l) / 2;
        return seg[p] = max(build(p * 2, l, mid, heights), build(p * 2 + 1, mid + 1, r, heights));
    }

    void query(int a, int b, int target, int &best, int p, int l, int r) {
        if(r < a || l > b) return;
        if(l < best && seg[p] > target) {
            if(l >= a && r <= b) best = min(best, r);
            int mid = l + (r - l) / 2;
            query(a, b, target, best, p * 2, l, mid);
            query(a, b, target, best, p * 2 + 1, mid + 1, r);
        }
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> solution;
        int n = heights.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, heights);
        for(const auto& q : queries) {
            if(q[0] == q[1]) solution.push_back(q[0]);
            else if(heights[min(q[0], q[1])] < heights[max(q[0], q[1])]) solution.push_back(max(q[0], q[1]));
            else {
                int best = INT_MAX;
                query(max(q[0], q[1]), n - 1, max(heights[q[0]], heights[q[1]]), best, 1, 0, n - 1);
                if(best == INT_MAX) solution.push_back(-1);
                else solution.push_back(best); 
            }
        }
        return solution;
    }
};