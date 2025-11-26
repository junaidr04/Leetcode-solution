class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> stack;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            while (!stack.empty() && stack.back() > num && stack.size() + (n - i - 1) >= k)
            {
                stack.pop_back();
            }
            if (stack.size() < k)
                stack.push_back(num);
        }
        return stack;
    }
};
