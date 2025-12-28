//Problem: Convert an Array Into a 2D Array With Conditions
// Platform: LeetCode
//Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
//Time: O(n) [Frequency count → O(n), Placement loop → O(n)]
//Space: O(n) [count map → O(n), placed map → O(n), result matrix → O(n)]
	​
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> count;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            count[num]++;
            if (count[num] > maxFreq)
            {
                maxFreq = count[num];
            }
        }
        vector<vector<int>> result(maxFreq);
        unordered_map<int, int> placed;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int rowIndex = placed[num];
            result[rowIndex].push_back(num);
            placed[num]++;
        }
        return result;
    }

};
