class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int ans = 0;
        for (int n : nums)
        {
            ans += n;
        }
        if (ans % 2 != 0)
            return false;
        int target = ans / 2;
        vector<int> dp(target + 1, false);
        dp[0] = true;
        for (int n : nums)
        {
            for (int i = target; i >= n; i--)
            {
                dp[i] = dp[i] || dp[i - n];
            }
        }
        return dp[target];
    }
};