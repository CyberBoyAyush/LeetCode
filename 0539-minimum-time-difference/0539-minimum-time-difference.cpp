class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;

        for (int i = 0; i < timePoints.size(); i++) {
            string curr = timePoints[i];

            int h = stoi(curr.substr(0, 2));
            int min = stoi(curr.substr(3, 2));

            int total = 60 * h + min;

            mins.push_back(total);
        }

        sort(mins.begin(), mins.end());

        int n = mins.size();
        int mini = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int diff = mins[i + 1] - mins[i];
            mini = min(mini, diff);
        }

        // Wrap-around difference
        int lastDiff = mins[0] + 1440 - mins[n - 1];
        mini = min(mini, lastDiff);

        return mini;
    }
};