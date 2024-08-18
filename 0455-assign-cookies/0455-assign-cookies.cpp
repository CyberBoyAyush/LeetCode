class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort both grred and size array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), m = s.size();

        int i = 0, j = 0;
        while(i <n && j < m){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};