class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        vector<vector<pair<int, int>>> graph;
        vector<bool> visited;
        queue<pair<int, int>> q;
        int biggest = routes.size();
        int n = 0;
        for(const auto& v : routes) {
            for(int i = 0; i < v.size(); i++) {
                int s = v.size();
                biggest = max({biggest, v[i], s});
            }
        }
        n = (biggest + 1) * 2;
        graph.resize(n);
        visited.resize(n);
        int stop_node = biggest + 1;
        for(const auto& v : routes) {
            stop_node++;
            for(int i = 0; i < v.size(); i++) {
                graph[stop_node].push_back({v[i], 0});
                graph[v[i]].push_back({stop_node, 0}); 
            }
        }
        q.push({source, 0});
        visited[source] = true;
        while(!q.empty()) {
            auto [vertex, buses] = q.front();
            q.pop();
            if(vertex == target) return buses;
            for(auto &p : graph[vertex]) {
                int j = p.first;
                if(!visited[j]) {
                    p.second = buses;
                    if(p.first > biggest) {
                        p.second++;
                    }
                    visited[j] = true;
                    q.push(p);
                }
            }
        }
        return -1;
    }
};