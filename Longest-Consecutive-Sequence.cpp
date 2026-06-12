auto f = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        s.reserve(nums.size());
        int lenght = 0;
        int longest = 0;
        for(int i : nums) {
            s.insert(i);
        }
        for(const int &j : s) {
            lenght = 0;
            if(s.find(j - 1) == s.end()) {
                int i = 1;
                lenght++;
                while(s.find(j + i) != s.end()) {
                    i++;
                    lenght++;
                }
            }
            if(lenght > longest) {
                longest = lenght;
            }
        }
        return longest;
    }
};