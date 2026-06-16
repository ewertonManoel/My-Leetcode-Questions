auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Union_find {
    vector<int> parent;
    vector<int> sz;
    public:
    Union_find(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
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
    int getSz(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int result = 0;
        int sz = (*max_element(nums.begin(), nums.end())) + 1;
        vector<int> vect(sz, -1);
        int n = nums.size();
        Union_find uf(n);
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int j = 2;
            int value = sqrt(x);
            while(j <= value) {
                if(x % j == 0) {
                    if(vect[j] != -1) {
                        uf.unite(i, vect[j]);
                    }
                    vect[j] = i;
                    result = max(result, uf.getSz(i));
                    while(x % j == 0) x /= j;
                    value = sqrt(x);
                }
                j++;
            }
            if(x > 1) {
                if(vect[x] != -1) {
                    uf.unite(i, vect[x]);
                }
                vect[x] = i;
                result = max(result, uf.getSz(i));
            }
        }
        return result;
    }
};