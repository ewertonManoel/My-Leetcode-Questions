int dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);

    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty()) {
        auto [path_distance, vertex] = pq.top();
        pq.pop();
        if(path_distance > distance[vertex]) continue;
        for(const auto& [weight, neighbor] : graph[vertex]) {
            int new_distance = path_distance + weight;
            if(new_distance < distance[neighbor]) {
                distance[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }
    int network_delay = 0;
    for(int i = 1; i < n; i++) {
        if(distance[i] == INT_MAX) return -1;
        network_delay = max(network_delay, distance[i]);
    }
    return network_delay;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        int min_time = 0;
        for(const auto& a : times) {
            graph[a[0]].push_back({a[2], a[1]});
        }
        return dijkstra(graph, k);
    }
};