auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Union_find {
    int parent[1001];
    int sz[1001];
    public:
    Union_find(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
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
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        Union_find uf(n);
        int n1 = requests.size();
        int n2 = restrictions.size();
        vector<bool> result(n1, true);
        for(int i = 0; i < n1; i++) {
            int x = requests[i][0];
            int y = requests[i][1];
            int x_find = uf.find(x);
            int y_find = uf.find(y);
            if(x_find == y_find) continue;
            for(int j = 0; j < n2; j++) {
                int x1_find = uf.find(restrictions[j][0]);
                int y1_find = uf.find(restrictions[j][1]);
                if(x_find == x1_find && y_find == y1_find || x_find == y1_find && y_find == x1_find) {
                    result[i] = false;
                    break;
                }
            }
            if(result[i]) uf.unite(x, y);
        }
        return result;
    }
};