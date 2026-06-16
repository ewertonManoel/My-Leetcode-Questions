auto f = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vect(n);
        for(int i = 0; i < n; i++) vect[i] = i;
        for(const auto &edge : edges) {
            vect[edge[1]] = -1;
        }
        vect.erase(remove(vect.begin(), vect.end(), -1), vect.end());
        return vect;
    }
};