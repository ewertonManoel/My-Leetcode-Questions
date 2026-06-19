auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()) {
            vector<int> path = move(q.front());
            q.pop();
            int vertex = path.back();
            if(vertex == n - 1) {
                paths.push_back(path);
                continue;
            }
            for(int i : graph[vertex]) {
                path.push_back(i);
                q.push(path);
                path.pop_back();
            }
        }
        return paths;
    }
};
