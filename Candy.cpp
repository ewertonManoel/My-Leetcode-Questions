class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> children(n);
        vector<pair<int, int>> ratings_candies(n + 2);
        ratings_candies[0] = {INT_MAX, 0};
        for(int i = 0; i < n; i++) {
            children[i] = {ratings[i], i};
            ratings_candies[i + 1] = {ratings[i], 0};
        }
        ratings_candies[n + 1] = {INT_MAX, 0};
        sort(children.begin(), children.end());
        int total_candies = 0;
        for(int i = 0; i < n; i++) {
            auto& [value, index] = children[i];
            index++;
            int& candies = ratings_candies[index].second;
            auto [l_value, l_candies] = ratings_candies[index - 1];
            auto [r_value, r_candies] = ratings_candies[index + 1];
            if(value > l_value && value > r_value) candies = max(l_candies, r_candies) + 1;
            else if(value > l_value) candies = l_candies + 1;
            else if(value > r_value) candies = r_candies + 1;
            else candies = 1;
            total_candies += candies;
        }
        return total_candies;
    }
};