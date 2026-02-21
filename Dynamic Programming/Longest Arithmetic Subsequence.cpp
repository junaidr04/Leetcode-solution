// Problem: Longest Arithmetic Subsequence
// Platform: leetcode
// Link: https://leetcode.com/problems/longest-arithmetic-subsequence/
// time complexity: O(n^2)
// space complexity: O(n^2)

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;                          // minimum AP length is 2
        vector<unordered_map<int, int>> dp(n); // dp[i][diff] = length of AP ending at i with difference diff
        int ans = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j]; // difference between current pair
                // If there is already an AP ending at j with this diff, extend it
                if (dp[j].count(diff))
                {
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else
                {
                    dp[i][diff] = 2; // else start new AP with length 2
                }
                // Update maximum length found so far
                if (dp[i][diff] > ans)
                {
                    ans = dp[i][diff];
                }
            }
        }
        return ans; // return the longest AP length
    }
};