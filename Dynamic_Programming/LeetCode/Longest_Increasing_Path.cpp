vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;

class Solution
{
public:
    int dfs(vector<vector<int>> &mat, int x, int y, vector<vector<int>> &dp)
    {

        if (dp[x][y])
            return dp[x][y];

        int ans = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || nx == m || ny < 0 || ny == n)
                continue;
            if (mat[x][y] < mat[nx][ny])
                ans = max(ans, 1 + dfs(mat, nx, ny, dp));
        }
        dp[x][y] = ans;
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>> &mat)
    {

        m = mat.size();
        if (m == 0)
            return 0;
        n = mat[0].size();
        if (!n)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = max(res, dfs(mat, i, j, dp));
            }
        }

        return res;
    }
};