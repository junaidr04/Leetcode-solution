///Problem: Palindrome String
//Platform: GeeksForGeeks
//Link: https://www.geeksforgeeks.org/problems/palindrome-string0817/1
//Time: O(n) [Compare two characters in each recursion call, Total recursion depth ≈ n/2],  Space: O(n) [Using recursion call stack, Stack depth ≈ n/2]


class Solution
{
public:
    bool chk(string &s, int l, int r)
    {
        if (l >= r)
            return true;
        if (s[l] != s[r])
            return false;
        return chk(s, l + 1, r - 1);
    }
    bool isPalindrome(string &s)
    {
        return chk(s, 0, s.length() - 1);
    }

};
