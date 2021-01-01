class Solution
{
public:
    bool find(vector<string> &dict, string str)
    {
        for (int i = 0; i < dict.size(); i++)
        {
            if (dict[i] == str)
                return true;
        }
        return false;
    }

    bool solve(string s, vector<string> &wordDict, vector<int> &memo)
    {
        if (s.empty())
            return true;
        int n = s.length();

        if (memo[n] != -1)
            return memo[n];

        memo[n] = 0;

        for (int i = 1; i <= n; i++)
        {
            string prefix = s.substr(0, i);
            if (find(wordDict, prefix) && solve(s.substr(i), wordDict, memo))
                memo[n] = 1;
        }

        return memo[n];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.length();
        vector<int> memo(n + 1, -1);
        return solve(s, wordDict, memo);
    }
};

class Solution_2
{
public:
    bool find(vector<string> &dict, string str)
    {
        for (int i = 0; i < dict.size(); i++)
        {
            if (dict[i] == str)
                return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.length();
        if (n == 0)
            return true;

        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++)
        { // len
            string prefix = s.substr(0, i);

            if (dp[i] == false && find(wordDict, prefix))
                dp[i] = true;

            if (dp[i])
            {
                if (i == n)
                    return true;

                for (int j = i + 1; j <= n; j++)
                { // length ahead of i
                    string s_prefix = s.substr(i, j - i);
                    if (dp[j] == false && find(wordDict, s_prefix))
                        dp[j] = true;

                    if (j == n && dp[j] == true)
                        return true;
                }
            }
        }
        return false;
    }
};