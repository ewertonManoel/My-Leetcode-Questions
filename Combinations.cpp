auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void recursion(vector<vector<int>> &vect, vector<int> &inner_vect, int i, int count, const int n, const int k) {
    if(count == k) {
        vect.push_back(inner_vect);
        return;
    }
    for(; i <= n; i++) {
        inner_vect.push_back(i);
        recursion(vect, inner_vect, i + 1, count + 1, n, k);
        inner_vect.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vect;
        vector<int> inner_vect;
        recursion(vect, inner_vect, 1, 0, n, k);
        return vect;
    }
};