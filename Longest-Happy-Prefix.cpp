auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int l = 0;
        int r = 1;
        vector<int> lps(n, 0);
        while(r < n) {
            if(s[r] == s[l]) {
                l++;
                lps[r] = l;
                r++;
            }
            else {
                if(l != 0) {
                    l = lps[l - 1];
                }
                else r++;
            }
        }
        return s.substr(0, lps.back());
    }
};