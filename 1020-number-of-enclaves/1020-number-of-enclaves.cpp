class Solution {
    // dfs solution is on GFG
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void DFS(int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                DFS(nrow, ncol, grid, vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        // check the row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                DFS(0, j, grid, vis);
            }
            if (grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                DFS(n - 1, j, grid, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                DFS(i, 0, grid, vis);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                DFS(i, m - 1, grid, vis);
            }
        }
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    // grid[i][j] = 0;
                    ans++;
                }
            }
        }

        return ans;
    }
};