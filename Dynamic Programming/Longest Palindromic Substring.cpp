class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int len = 2; len <= n; len++)
        {
            for (int l = 0; l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                if (s[l] == s[r])
                {
                    if (len <= 3)
                    {
                        dp[l][r] = true;
                    }
                    else
                    {
                        dp[l][r] = dp[l + 1][r - 1];
                    }
                }
                else
                {
                    dp[l][r] = false;
                }
                if (dp[l][r] && len > maxLen)
                {
                    maxLen = len;
                    start = l;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};