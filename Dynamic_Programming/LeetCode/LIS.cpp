class Solution
{
public:
    int lengthOfLIS(vector<int> &arr)
    {

        int n = arr.size();
        if (n == 0)
            return 0;
        int dp[n]; // LIS ending at i
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i] && dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};