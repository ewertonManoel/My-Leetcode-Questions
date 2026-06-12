auto fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

inline void update(vector<int>& fenwickTree, int i, int delta) {
    for(; i < fenwickTree.size(); i += (i & -i)) {
        fenwickTree[i] += delta;
    }
}

inline void query(vector<int>& fenwickTree, int i, long long &sum) {
    for(; i > 0; i -= (i & -i)) {
        sum += fenwickTree[i];
    }
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long sum = 0;
        vector<long long> ranking;
        ranking.reserve(2 * nums.size());
        for(int i : nums) {
            ranking.push_back((long long)i);
            ranking.push_back(2LL * (long long)i);
        }
        sort(ranking.begin(), ranking.end());
        ranking.erase(unique(ranking.begin(), ranking.end()), ranking.end());

        vector<int> fenwickTree(ranking.size() + 1, 0);
        for(int i = nums.size() - 1; i >= 0; i--) {
            int index = lower_bound(ranking.begin(), ranking.end(), nums[i]) - ranking.begin();
            int index2 = lower_bound(ranking.begin(), ranking.end(), (long long) nums[i] * 2LL) - ranking.begin();
            query(fenwickTree, index, sum);
            update(fenwickTree, index2 + 1, 1);
        }

        return sum;
    }
};