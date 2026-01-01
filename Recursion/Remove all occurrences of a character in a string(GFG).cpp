// Problem: Remove all occurrences of a character in a string
// Platform: GeeksForGeeks
// Link: https://www.geeksforgeeks.org/problems/remove-all-occurrences-of-a-character-in-a-string/1
// Time: O(n) [Each character can be erased + checked once at most, total linear time]
// space: O(n) [For recursion stack, For recursion stack]

class Solution
{
    void chk(string &s, char c, int i)
    {
        if (i == s.size())
            return;
        if (s[i] == c)
        {
            s.erase(i, 1);
            chk(s, c, i);
        }
        else
        {
            chk(s, c, i + 1);
        }
    }

public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c)
    {
        chk(s, c, 0);
    }
};