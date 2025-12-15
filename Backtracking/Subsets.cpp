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