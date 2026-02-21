// Problem: Minimum Number of Days to Make m Bouquets
// Platform: leetcode
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// time complexity: O(n * log(maxDay))
// space complexity: O(1)

class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int day)
    {
        int count = 0, noOfB = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                noOfB += (count / k);
                count = 0;
            }
        }
        noOfB += (count / k);
        return noOfB >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = INT_MAX, high = INT_MIN;
        if ((long long)m * k > bloomDay.size())
            return -1;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(bloomDay, m, k, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};