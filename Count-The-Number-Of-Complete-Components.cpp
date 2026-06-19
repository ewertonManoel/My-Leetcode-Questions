#define sz 50

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[sz];
        vector<bool> visited(sz, false);
        queue<int> q;
        int complete = 0;
        for(const auto &a : edges) {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        for(int i = 0; i < n; i++) {
            int k = 0;
            int degree_sum = 0;
            if(visited[i]) continue;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                k++;
                int vertex = q.front();
                q.pop();
                degree_sum += graph[vertex].size();
                for(const int &j : graph[vertex]) {
                    if(!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            if(degree_sum == k * (k - 1)) complete++;
        }
        return complete;
    }
};