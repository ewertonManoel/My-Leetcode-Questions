class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> goal(26, 0);
        vector<int> window(26, 0);

        if (s1.size() > s2.size()) return false;

        for(int i = 0; i < s1.size(); i++) {
            goal[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        int l = 0;
        int r = s1.size() - 1;

        if(window == goal) return true;
        while(r + 1 < s2.size()) {
            int l_value = s2[l] - 'a';
            r++;
            int r_value = s2[r] - 'a';
            window[r_value]++;
            window[l_value]--;
            l++;
            if(window == goal) return true;
        }
        return false;
    }
};