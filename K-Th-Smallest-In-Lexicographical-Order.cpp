void calculate(int n, long long minThreshold, long long maxThreshold, long long& steps) {
    while(minThreshold <= n) {
        steps += min(maxThreshold, (long long)(n + 1)) - minThreshold;
        minThreshold *= 10;
        maxThreshold *= 10;
    } 
}

class Solution {
public:
    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;
        while(k > 0) {
            long long steps = 0;
            calculate(n, cur, cur + 1, steps);
            if(k >= steps) {
                k -= steps;
                cur++;
            }
            else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
};