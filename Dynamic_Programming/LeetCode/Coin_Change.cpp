#define MAX 10005

class Solution
{
public:
    int coinChange(vector<int> &coins, int val)
    {

        int n = coins.size();
        if (val == 0)
            return 0;

        queue<pair<int, int>> pq;
        pq.push({val, 0});

        vector<bool> visited(MAX, false);
        visited[val] = true;

        while (!pq.empty())
        {

            int curr = pq.front().first;
            int d = pq.front().second;
            //        cout<<curr<<endl;
            pq.pop();

            if (!curr)
                return d;

            for (int i = 0; i < n; i++)
            {
                int target = curr - coins[i];
                if (target >= 0 && !visited[target])
                {
                    visited[target] = true;
                    pq.push({target, d + 1});
                }
            }
        }
        return -1;
    }
};

#define MAX 10005

class Solution
{
public:
    int coinChange(vector<int> &coins, int val)
    {

        int n = coins.size();
        if (val == 0)
            return 0;

        int dp[n + 1][val + 1];

        for (int i = 0; i <= val; i++)
            dp[0][i] = -1;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= val; j++)
            {
                if (coins[i - 1] <= j)
                {
                    int a = dp[i - 1][j];
                    int b = dp[i][j - coins[i - 1]];
                    if (a == -1 && b == -1)
                        dp[i][j] = -1;
                    else if (a == -1)
                        dp[i][j] = 1 + b;
                    else if (b == -1)
                        dp[i][j] = a;
                    else
                        dp[i][j] = min(a, 1 + b);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][val];
    }
};