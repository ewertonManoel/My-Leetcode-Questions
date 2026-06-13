auto fast = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string shortestPalindrome(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        string st = s + "_" + s1;
        int m = st.size();
        vector<int> lps(m, 0);
        int l = 0;
        int r = 1;
        while(r < m) {
            if(st[r] == st[l]) {
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
        string s2 = s.substr(lps.back());
        reverse(s2.begin(), s2.end());
        return s2 + s;
    }
};