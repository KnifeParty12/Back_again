int m,n;

class Solution {
public:

    int solve(vector<vector<int>>& grid,vector<vector<int>>& memo, int x, int y){
        if(x == m-1 && y == n-1) return grid[x][y];
        if(x ==m || y == n) return INT_MAX;
        
        if(memo[x][y]!= -1) return memo[x][y];
        
         int a = solve(grid,memo,x+1,y);
         int b = solve(grid,memo,x,y+1);
         
         memo[x][y] = grid[x][y] + min(a,b);
        
        return memo[x][y];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
         
        m = grid.size();
        if(m == 0) return 0;
         n = grid[0].size();
        
        vector<vector<int>>memo(m,vector<int>(n,-1));
        
        return solve(grid,memo,0,0);

    }
};