// Problem: 3Sum Closest
// Platform: leetcode
// Link: https://leetcode.com/problems/3sum-closest/
// time complexity: O(n^2)
// space complexity: O(1)

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int bestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)   //i er por jeno aro 2 ta number thake
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - bestSum))
                {
                    bestSum = sum;
                }
                else if (abs(target - sum) == abs(target - bestSum))
                {
                    bestSum = max(bestSum, sum);
                }
                if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return bestSum;
    }

};
