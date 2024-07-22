class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<string, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = make_pair(names[i], heights[i]);
        }

        auto lambda = [](auto &p1, auto &p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        for(int i = 0; i < n; i++) {
            names[i] = vec[i].first;
        }

        return names;
    }
};
