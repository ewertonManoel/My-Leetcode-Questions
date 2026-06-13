class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq(target.begin(), target.end());
        long long sum = 0;
        for(int i : target) sum += i;
        while(pq.top() != 1) {
            long long values = sum - pq.top();
            if(values == 1) return true;
            if(values == 0 || pq.top() <= values) return false;
            long long prev = pq.top() % values;
            if(prev == 0) return false;
            sum -= pq.top() - prev;
            pq.pop();
            pq.push(prev);
        }
        return true;
    }
};