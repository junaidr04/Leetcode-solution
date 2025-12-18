class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &candidates, int target, vector<int> temp)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        for (int i = idx; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};