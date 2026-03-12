// Problem: Minimum Swaps to Make Strings Equal
// Platform: LeetCode
// Link: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
// time complexity: O(n) where n is the length of the input strings, since we need to iterate through both strings to count the number of 'x' characters and determine if they can be made equal.
// space complexity: O(1) since we are using a constant amount of extra space to store the counts and calculate the number of swaps needed.

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        if (s1.size() != s2.size())
        {
            return -1;
        }
        int X = 0, Y = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
            {
                X++;
            }
            else if (s1[i] == 'y' && s2[i] == 'x')
            {
                Y++;
            }
        }
        if ((X + Y) % 2)
            return -1;
        return (X / 2) + (Y / 2) + 2 * (X % 2);
    }
};