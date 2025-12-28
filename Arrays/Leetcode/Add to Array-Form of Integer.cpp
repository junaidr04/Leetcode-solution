///Problem: Add to Array-Form of Integer
//Platform: LeetCode
//Link: https://leetcode.com/problems/add-to-array-form-of-integer/description/
//Time: O(n), Space: O(n)


class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans;
        int i = num.size() - 1;
        while (i >= 0 || k > 0)
        {
            if (i >= 0)
            {
                k += num[i];
                i--;
            }
            ans.push_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};
