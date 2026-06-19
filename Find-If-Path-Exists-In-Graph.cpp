class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        queue<int> q;
        for(const auto &a : edges) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int vertex = q.front();
            q.pop();
            if(vertex == destination) return true;
            for(int i : adj[vertex]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;   
    }
};
