// Problem: Combination Sum III
// Platform: LeetCode
// Link: https://leetcode.com/problems/combination-sum-iii/
// time complexity: O(2^9)
// space complexity: O(k) where k is the number of valid combinations

class Solution
{
public:
    void solve(int start, int k, int n, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if (n < 0 || curr.size() >= k)
        {
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            curr.push_back(i);
            solve(i + 1, k, n - i, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, k, n, curr, ans);
        return ans;
    }
};