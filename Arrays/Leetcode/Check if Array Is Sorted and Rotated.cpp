// Problem: Check if Array Is Sorted and Rotated
// Platform: LeetCode
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
//Time: O(n) [Loop traverses the array only once]
//Space: O(1)​ [No extra data structure]


class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                count++;
            }
        }
        if (count > 1)
        {
            return false;
        }
        return true;
    }

};
