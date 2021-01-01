#define pb push_back
int m, n;

class Solution
{
public:
    int area_under_histogram(vector<int> &hist)
    {

        stack<int> s;
        int sz = hist.size();
        int tp;
        int temp_area;
        int ans = 0;

        int i = 0;
        while (i < sz)
        {
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);

            else
            {
                tp = s.top();
                s.pop();

                temp_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
                if (ans < temp_area)
                    ans = temp_area;
            }
        }

        while (!s.empty())
        {
            tp = s.top();
            s.pop();
            temp_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (ans < temp_area)
                ans = temp_area;
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>> &arr)
    {

        m = arr.size();
        if (m == 0)
            return 0;
        n = arr[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[0][i] = arr[0][i] - '0';

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '1')
                {
                    dp[i][j] = 1 + dp[i - 1][j];
                }
                else
                    dp[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> hist;
            for (int j = 0; j < n; j++)
                hist.pb(dp[i][j]);
            ans = max(ans, area_under_histogram(hist));
        }

        return ans;
    }
};