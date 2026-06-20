class UnionFind {
public:
    vector<int> sz;
    vector<int> parent;
    UnionFind(int n) {
        sz.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);

        if(x_root == y_root) return;
        if(sz[x_root] < sz[y_root]) {
            swap(x_root, y_root);
        }
        parent[y_root] = x_root;
        sz[x_root] += sz[y_root];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n + 1);
        vector<vector<int>> dist(n);
        int score = INT_MAX;
        for(const auto &a : roads) {
            uf.unite(a[0], a[1]);
        }
        for(const auto &b : roads) {
            if(uf.same(b[0], 1)) {
                score = min(score, b[2]);
            }
        }
        return score;
    }
};