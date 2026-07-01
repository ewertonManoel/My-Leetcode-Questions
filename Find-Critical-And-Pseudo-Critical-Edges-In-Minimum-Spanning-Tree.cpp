int find(vector<int>& parent, int x) {
    if(x != parent[x]) parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(vector<int>& parent, vector<int>& sz, int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);

    if(x_root == y_root) return;
    if(sz[x_root] < sz[y_root]) swap(x_root, y_root);
    parent[y_root] = x_root;
    sz[x_root] += sz[y_root];
}

bool same(vector<int>& parent, int x, int y) {
    return find(parent, x) == find(parent, y);
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical;
        vector<int> pseudoCritical;
        int m = edges.size();
        for(int i = 0; i < m; i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [] (auto& a, auto& b) {return a[2] < b[2];} );

        vector<int> parent(n);
        vector<int> sz(n, 1);
        for(int k = 0; k < n; k++) parent[k] = k;

        int cost = 0;
        for(int i = 0; i < m; i++) {
            if(same(parent, edges[i][0], edges[i][1])) continue;
            unite(parent, sz, edges[i][0], edges[i][1]);
            cost += edges[i][2];
        }

        for(int j = 0; j < m; j++) {
            int new_cost = 0;
            for(int k = 0; k < n; k++) {
                parent[k] = k;
                sz[k] = 1;
            }
            int op = 0;
            for(int i = 0; i < m; i++) {
                if(i == j) continue;
                if(same(parent, edges[i][0], edges[i][1])) continue;
                unite(parent, sz, edges[i][0], edges[i][1]);
                new_cost += edges[i][2];
                op++;
            }
            if(new_cost > cost || op < n - 1) {
                critical.push_back(edges[j][3]);
            }
            else {
                int new_cost = 0;
                for(int k = 0; k < n; k++) {
                    parent[k] = k;
                    sz[k] = 1;
                }
                unite(parent, sz, edges[j][0], edges[j][1]);
                new_cost += edges[j][2];
                for(int i = 0; i < m; i++) {
                    if(same(parent, edges[i][0], edges[i][1])) continue;
                    unite(parent, sz, edges[i][0], edges[i][1]);
                    new_cost += edges[i][2];
                }
                if(new_cost == cost) {
                    pseudoCritical.push_back(edges[j][3]);
                }
            }
        }
        return {critical, pseudoCritical};
    }
};