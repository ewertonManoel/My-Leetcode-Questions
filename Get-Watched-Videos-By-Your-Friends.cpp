class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool> visited(friends.size(), false);
        unordered_map<string, int> mp;
        vector<pair<int, string>> frequency;
        vector<string> answer;
        queue<int> q;
        int lv = 0;
        visited[id] = true;
        q.push(id);
        while(!q.empty()) {
            if(lv == level) break;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int vertex = q.front();
                q.pop();
                for(const int &j : friends[vertex]) {
                    if(!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            lv++;
        }
        while(!q.empty()) {
            for(const string &s : watchedVideos[q.front()]) mp[s]++;
            q.pop();
        }
        frequency.reserve(mp.size());
        for(const auto& items : mp) {
            frequency.push_back({items.second, items.first});
        }
        answer.reserve(frequency.size());
        sort(frequency.begin(), frequency.end());
        for(const auto &p : frequency) {
            answer.push_back(p.second);
        }
        return answer;
    }
};