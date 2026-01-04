// Problem: Subsets
// Platform: Leetcode
// Link: https://leetcode.com/problems/subsets/description/
// Time: O(2ⁿ × n) [Total subsets = 2ⁿ, At most n elements are copied to create each subset(ans.push_back(subset))]
// space: O(2ⁿ × n) [For storing all subsets, and O(n) for recursion stack]

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &nums, vector<int> &subset)
    {
        if (idx == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        solve(idx + 1, nums, subset);
        subset.pop_back();
        solve(idx + 1, nums, subset);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        solve(0, nums, subset);
        return ans;
    }
};