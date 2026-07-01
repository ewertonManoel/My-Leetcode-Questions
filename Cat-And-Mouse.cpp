#define mouseWin 1
#define catWin 2

void bfs(vector<vector<int>>& graph, vector<vector<vector<int>>>& memo, vector<vector<vector<int>>>& degree, queue<tuple<int, int, int>>& q) {
    while(!q.empty()) {
        auto [mouse, cat, turn] = q.front(); q.pop();
        int prev_turn = 1 - turn;
        if(prev_turn == 0) {
            for(int prev_mouse : graph[mouse]) {
                if(memo[prev_mouse][cat][prev_turn] != 0) continue;
                if(memo[mouse][cat][turn] == mouseWin) {
                    memo[prev_mouse][cat][prev_turn] = mouseWin;
                    q.push({prev_mouse, cat, prev_turn});
                }
                else {
                    degree[prev_mouse][cat][prev_turn]--;
                    if(degree[prev_mouse][cat][prev_turn] == 0) {
                        memo[prev_mouse][cat][prev_turn] = catWin;
                        q.push({prev_mouse, cat, prev_turn});
                    }
                }
            }
        }

        else {
            for(int prev_cat : graph[cat]) {
                if(memo[mouse][prev_cat][prev_turn] != 0 || prev_cat == 0) continue;
                if(memo[mouse][cat][turn] == catWin) {
                    memo[mouse][prev_cat][prev_turn] = catWin;
                    q.push({mouse, prev_cat, prev_turn});
                }
                else {
                    degree[mouse][prev_cat][prev_turn]--;
                    if(degree[mouse][prev_cat][prev_turn] == 0) {
                        memo[mouse][prev_cat][prev_turn] = mouseWin;
                        q.push({mouse, prev_cat, prev_turn});
                    }
                }
            }
        }
    }
}

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                degree[i][j][0] = graph[i].size();
                degree[i][j][1] = graph[j].size();
            }
            for(int k : graph[0]) degree[i][k][1]--;
        }
        for(int i = 1; i < n; i++) {
            q.push({0, i, 0});
            q.push({0, i, 1});
            memo[0][i][0] = mouseWin;
            memo[0][i][1] = mouseWin;
        }
        for(int j = 1; j < n; j++) {
            q.push({j, j, 0});
            q.push({j, j, 1});
            memo[j][j][0] = catWin;
            memo[j][j][1] = catWin;
        }
        bfs(graph, memo, degree, q);
        return memo[1][2][0];
    }
};