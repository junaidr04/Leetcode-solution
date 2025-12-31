// Problem: Number of occurrence
// Platform: GeeksForGeeks
// Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Time: O(n) [Each element is checked once.]
// space: O(n) [recursion call stack; worst case = array size]


class Solution
{
public:
    int chk(vector<int> &arr, int target, int i)
    {
        if (i == arr.size())
            return 0;
        if (arr[i] == target)
            return 1 + chk(arr, target, i + 1);
        else
            return chk(arr, target, i + 1);
    }
    int countFreq(vector<int> &arr, int target)
    {
        return chk(arr, target, 0);
    }
};
