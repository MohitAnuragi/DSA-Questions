class Solution { // striver
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; // store position
        int days = 0, cnt = 0, tot = 0;  // rotten+fresh
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        // BFS 
        while(!q.empty()) {
            int size = q.size(); 
            cnt += size;         
            
            for(int k = 0; k < size; k++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nr = dr[i] + r;
                    int nc = dc[i] + c;
                    
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != 1)
                        continue;  
                    
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
            // increase the days
            if(!q.empty()) days++;  
        }
        
        return tot == cnt ? days : -1;
    }
};