vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegree(n, 0);
    vector<int> topologicalOrder(n, 0);
    queue<int> q;

    for(const auto& a : graph) {
        for(int i : a) {
            indegree[i]++;            
        }
    }
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    int index = 0;
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        topologicalOrder[index++] = vertex;
        for(const auto& neighbor : graph[vertex]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) q.push(neighbor);
        }
    }
    if(index < n) return {};
    else return topologicalOrder;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& a : prerequisites) {
            graph[a[1]].push_back(a[0]);
        }
        return topologicalSort(graph);
    }
};