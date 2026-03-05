// Problem: How Many Numbers Are Smaller Than the Current Number
// Platform: leetcode
// Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// time complexity: O(nlogn) or O(n) if we use counting sort
// space complexity: O(n) or O(1) if we use counting sort

class Solution
{
public:
    // Function to find how many numbers are smaller than current for each element
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        // Make a copy of the original array because we will sort it
        vector<int> s = nums;
        // Sort the copied array in ascending order
        sort(s.begin(), s.end());
        // Create a hash map to store: number -> count of smaller numbers
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            // If this number is not already in the map
            if (mp.count(s[i]) == 0)
            {
                // The index i = number of elements smaller than s[i]
                mp[s[i]] = i;
            }
        }
        vector<int> ans;
        // Loop through the original array
        for (int x : nums)
        {
            // Append the count of smaller numbers from the map
            ans.push_back(mp[x]);
        }
        return ans;
    }
};