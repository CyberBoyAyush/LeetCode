class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n);
        unordered_map<string, int> mpp; // stores the mapping of mail to node

        // intializing parent array
        // Initialize parent and rank vectors
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) {
                    // mail not in map
                    mpp[mail] = i; // mapping mail to ith node
                } else {
                    // mail is laready in map
                    Union(i, mpp[mail]); // connect curr node  with the node
                                         // detail we found in map
                }
            }
        }

        vector<string> mergeList[n];
        for (auto it : mpp) {
            string mail = it.first;
            int node = find(it.second);

            mergeList[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeList[i].size() == 0) {
                continue; // empty list it is
            }

            // sort the mail
            sort(mergeList[i].begin(), mergeList[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeList[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};