void backtracking(vector<pair<int, int>> adj[], vector<int> &values, bool visited[], int i, int time, const int maxTime, int quality, int &maxQuality) {
    if(i == 0) maxQuality = max(maxQuality, quality);
    for(const auto &neighbors : adj[i]) {
        int addedTime = neighbors.second;
        if(time + addedTime > maxTime) continue;
        time += addedTime;
        bool changed = false;
        if(!visited[neighbors.first]) {
            quality += values[neighbors.first];
            changed = true;
        }
        visited[neighbors.first] = true;
        backtracking(adj, values, visited, neighbors.first, time, maxTime, quality, maxQuality);
        if(changed) {
            quality -= values[neighbors.first];
            visited[neighbors.first] = false;
        }
        time -= addedTime;
    }
    return;
}

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<pair<int, int>> adj[1001];
        bool visited[1001] = {};
        visited[0] = true;
        for(const auto &a : edges) {
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        int maxQuality = 0;
        backtracking(adj, values, visited, 0, 0, maxTime, values[0], maxQuality);
        return maxQuality;
    }
};
