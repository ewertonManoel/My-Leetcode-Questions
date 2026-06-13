class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> vect;
        dq.push_back(0);
        for(int i = 1; i < k; i++) {
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vect.push_back(nums[dq.front()]);
        int l = 0;
        int r = k - 1;
        while(r < nums.size() - 1) {
            l++;
            r++;
            if(dq.front() < l) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
            vect.push_back(nums[dq.front()]);
        }
    return vect;
    }
};