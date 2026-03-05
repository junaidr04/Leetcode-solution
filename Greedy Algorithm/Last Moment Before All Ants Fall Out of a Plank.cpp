// Problem: Last Moment Before All Ants Fall Out of a Plank
// Platform: leetcode
// Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/
// time complexity: O(L + R)
// space complexity: O(1)

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int ans = 0;
        for (int pos : left)
        {
            ans = max(pos, ans);
        }
        for (int pos : right)
        {
            ans = max(ans, n - pos);
        }
        return ans;
    }
};