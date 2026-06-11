void happy(string &s, int &count, int j, const int n, const int k) {
    if(j == n) {
        count++;
        return;
    }
    for(int i = 0; i < 3; i++) {
        if(!s.empty() && s.back() - 'a' == i) continue;
        s.push_back('a' + i);
        happy(s, count, j + 1, n, k);
        if(count == k) return;
        s.pop_back();
    }
}

class Solution {
public:
    string getHappyString(int n, int k) {
        int count = 0;
        string s;
        happy(s, count, 0, n, k);
        return s;
    }
};