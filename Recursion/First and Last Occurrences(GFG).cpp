/// Problem: First and Last Occurrences
// Platform: GeeksForGeeks
// Link: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Time: O(n) [Each element is checked once.]
// space: O(n) [For recursion call stack]

class Solution
{
public:
    void solve(vector<int> &arr, int x, int i, int &first, int &last)
    {
        if (i == arr.size())
            return;
        if (arr[i] == x)
        {
            if (first == -1)
                first = i;
            last = i;
        }
        solve(arr, x, i + 1, first, last);
    }
    vector<int> find(vector<int> &arr, int x)
    {
        int first = -1, last = -1;
        solve(arr, x, 0, first, last);
        return {first, last};
    }
};