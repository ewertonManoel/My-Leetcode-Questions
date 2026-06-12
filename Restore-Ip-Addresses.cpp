#define number_dots 3

bool isValid(string &s, int i, int j) {
    string num;
    for(; i < j; i++) num += s[i];
    int n = num.size();
    if(n > 3 || n < 1 || n > 1 && num[0] == '0' || stoi(num) > 255) return false;
    return true;
}

void recursion(vector<string> &vect, string &s, int i, int k) {
    if(k == number_dots) {
        if(isValid(s, i + 1, s.size())) {
            vect.push_back(s);
        }
        return;
    }
    for(int j = i + 2; j < s.size(); j++) {
        if(!isValid(s, i + 1, j)) continue;
        s.insert(j, ".");
        recursion(vect, s, j, k + 1);
        s.erase(j, 1);
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> vect;
        int n = s.size();
        if(n > 12 || n < number_dots) return vect;
        recursion(vect, s, -1, 0);
        return vect;
    }
};