class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, j = 1;
        while(i < nums.size()) {
            if(nums[i] >= 1 && nums[i] - 1 < nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else i++;
       }
       for(; j <= nums.size(); j++) {
            if(nums[j - 1] != j) {
                return j; 
            }
       }
       return j;
    }
};