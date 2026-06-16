auto f = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> vect(n+1);
        vector<int> degree(n+1, 0);
        vector<int> to_fix;
        for(const auto &a : edges) {
            int u = a[0];
            int v = a[1];
            degree[u]++;
            degree[v]++;
            vect[u].insert(v);
            vect[v].insert(u);
        }
        int sz = 0;
        for(int i = 1; i <= n; i++) {
            if(degree[i] % 2 != 0) {
                to_fix.push_back(i);
                sz = to_fix.size();
                if(sz > 4) return false;
            }
        }
        if(sz == 0) return true;
        else if(sz % 2 != 0) return false;
        else {
            int a = to_fix[0];
            int b = to_fix[1];
            if(sz == 4) {
                int c = to_fix[2];
                int d = to_fix[3];

                if(vect[a].find(b) == vect[a].end() && vect[c].find(d) == vect[c].end()) return true;
                if(vect[a].find(c) == vect[a].end() && vect[b].find(d) == vect[b].end()) return true;
                if(vect[a].find(d) == vect[a].end() && vect[b].find(c) == vect[b].end()) return true;
            }
            if(sz == 2) {
                if(vect[a].find(b) == vect[a].end()) return true;
                for(int i = 1; i <= n; i++) {
                    if(vect[to_fix[0]].find(i) == vect[to_fix[0]].end() &&
                    vect[to_fix[1]].find(i) == vect[to_fix[1]].end()) {
                        return true;
                    }
                }
            }
            return false;  
        }
    }
};