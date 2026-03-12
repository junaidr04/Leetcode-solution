// Problem: License Key Formatting
// Platform: LeetCode
// Link: https://leetcode.com/problems/license-key-formatting/
// time complexity: O(n) where n is the length of the input string
// space complexity: O(n) since we are creating a new string to store the formatted license key

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ans = "";
        for (char c : s)
        {
            if (c != '-')
            {
                ans += c;
            }
        }
        for (char &c : ans)
        {
            c = toupper(c);
        }
        string temp = "";
        int count = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            temp += ans[i];
            count++;
            if (count == k)
            {
                temp += '-';
                count = 0;
            }
        }
        if (!temp.empty() && temp.back() == '-')
        {
            temp.pop_back();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};