enum Color {
    red = 0,
    blue = 1,
    uncolored = 2
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, Color>> graph[100];
        bool visited[100][2] = {false};
        queue<pair<int, Color>> q;
        vector<int> answer(n, -1);
        for(const auto &r : redEdges) {
            graph[r[0]].push_back({r[1], red});
        }
        for(const auto &b : blueEdges) {
            graph[b[0]].push_back({b[1], blue});
        }
        q.push({0, uncolored});
        answer[0] = 0;
        int lv = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int node = q.front().first;
                int color_node = q.front().second;
                q.pop();
                for(const auto &p : graph[node]) {
                    auto[index, color] = p;
                    if(!visited[index][color] && color != color_node) {
                        if(answer[index] == -1) answer[index] = lv;
                        q.push(p);
                        visited[index][color] = true;
                    }
                }
            }
            lv++;
        }
        return answer;         
    }
};