// Problem: Split Array Largest Sum
// Platform: LeetCode
// Link: https://leetcode.com/problems/split-array-largest-sum/
// time complexity: O(n log(sum of elements in the array)) where n is the size of the array
// space complexity: O(1)

class Solution
{
public:
    bool possible(int mid, vector<int> &arr, int k)
    {
        int count = 1, sum = 0;
        for (int x : arr)
        {
            sum += x;
            if (sum > mid)
            {
                count++;
                sum = x;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (possible(mid, nums, k))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};