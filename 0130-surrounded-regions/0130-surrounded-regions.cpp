class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // mark in visited
        vis[row][col] = 1;

        // check top,bottom,left and right
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // check boundary
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // visited matrix for storing the  'O' at border
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 1 -> traverse in border and find the 'O' ans traverse it using dfs

        // rows traversal -> first and last
        for (int j = 0; j < m; j++) {
            // first row
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat);
            }
            // last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat);
            }
        }

        // col traversal -> first and last
        for (int i = 0; i < n; i++) {
            // first row
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            // last row
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat);
            }
        }

        // 2 -> convert all the 'O' to 'X'
        // traversal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' && !vis[i][j]) {
                    // we change it
                    mat[i][j] = 'X';
                }
            }
        }
    }
};