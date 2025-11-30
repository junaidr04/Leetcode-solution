class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int inf = 1e9;
        vector<int> dp(amount + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int c : coins)
            {
                if (i - c >= 0)
                {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] == inf)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};