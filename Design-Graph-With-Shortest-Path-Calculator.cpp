vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
    int n = graph.size();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    vector<long long> distance(n, LLONG_MAX);

    pq.push({0, src});
    distance[src] = 0;

    while(!pq.empty()) {
        auto [current_distance, vertex] = pq.top();
        pq.pop();
        if(current_distance > distance[vertex]) continue;
        for(const auto& [neighbor, weight] : graph[vertex]) {
            long long new_distance = current_distance + weight;
            if(new_distance < distance[neighbor]) {
                distance[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }
    return distance;
}

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> reversedGraph(n);

        for(const auto& a : edges) { 
            graph[a[0]].push_back({a[1], a[2]});
            reversedGraph[a[1]].push_back({a[0], a[2]});
        }
        vector<long long> src1Dist = dijkstra(graph, src1);
        vector<long long> src2Dist = dijkstra(graph, src2);
        vector<long long> destDist = dijkstra(reversedGraph, dest);
        long long subgraph_weight = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            if(src1Dist[i] == LLONG_MAX || src2Dist[i] == LLONG_MAX || destDist[i] == LLONG_MAX) continue;
            subgraph_weight = min(subgraph_weight, (src1Dist[i] + src2Dist[i] + destDist[i]));
        }
        if(subgraph_weight == LLONG_MAX) return -1;
        return subgraph_weight;
    }
};