// Problem: Interval List Intersections
// Platform: leetcode
// Link: https://leetcode.com/problems/interval-list-intersections/
// time complexity: O(n + m) [where n and m are the lengths of the two interval lists]
// space complexity: O(min(n, m))

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int str = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (str <= end)
            {
                ans.push_back({str, end});
            }
            if (firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};