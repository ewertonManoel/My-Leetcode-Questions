int dijkstra(vector<vector<pair<int, int>>>& graph, int source, const int distanceThreshold) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);

    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty()) {
        auto [current_distance, vertex] = pq.top();
        pq.pop();
        if(current_distance > distance[vertex]) continue;
        for(const auto& [weight, neighbor] : graph[vertex]) {
            int new_distance = current_distance + weight;
            if(new_distance < distance[neighbor]) {
                distance[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }
    int validCities = 0;
    for(int d : distance) {
        if(d <= distanceThreshold) validCities++;
    }
    return validCities;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);

        for(const auto& a : edges) { 
            graph[a[0]].push_back({a[2], a[1]});
            graph[a[1]].push_back({a[2], a[0]});   
        }
        int min_neighbors = INT_MAX;
        int result = 0;
        for(int city = 0; city < n; city++) {
            int neighboringCities = dijkstra(graph, city, distanceThreshold);
            if(neighboringCities <= min_neighbors) {
                result = city;
                min_neighbors = neighboringCities;
            }
        }
        return result;
    }
};