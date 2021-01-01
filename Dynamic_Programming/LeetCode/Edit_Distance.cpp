int m, n; // word1 and word2

class Solution
{
public:
    int solve(string s, string t, vector<vector<int>> &memo)
    {
        return 12;
    }

    int minDistance(string word1, string word2)
    {

        // convert word1 to word2
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[0][i] = i; // word2 is NULL hence all deletions
        for (int i = 0; i <= m; i++)
            dp[i][0] = i; // word1 is NULL hence all insertions

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[m - i] == word2[n - j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};