class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
                else {
                    isWater[i][j] = -1;
                }
            }
        }
        while(!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            if(y - 1 >= 0) {
                if(isWater[y - 1][x] == -1) {
                    isWater[y - 1][x] = isWater[y][x] + 1;
                    q.push({y - 1, x});
                }
            }
            if(x - 1 >= 0) {
                if(isWater[y][x - 1] == -1) {
                    isWater[y][x - 1] = isWater[y][x] + 1;
                    q.push({y, x - 1});
                }
            }
            if(y + 1 < m) {
                if(isWater[y + 1][x] == -1) {
                    isWater[y + 1][x] = isWater[y][x] + 1;
                    q.push({y + 1, x});
                }
            }
            if(x + 1 < n) {
                if(isWater[y][x + 1] == -1) {
                    isWater[y][x + 1] = isWater[y][x] + 1;
                    q.push({y, x + 1});
                }
            }
        }
        return isWater;
    }
};