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