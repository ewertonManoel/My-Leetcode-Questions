class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> Z(n, 0);
        Z[0] = n;
        int l = 0;
        int r = 0;
        for(int i = 1; i < n; i++) {
            if(i <= r) {
                Z[i] = min(r - i + 1, Z[i - l]);
            }
            while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) {
                Z[i]++;
            }
            if(i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        long long score = 0;
        for(int i : Z) score += i;
        return score;
    }
};