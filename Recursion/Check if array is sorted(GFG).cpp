///Problem: Check if array is sorted
//Platform: GeeksForGeeks
//Link: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
//Time: O(n) [Each element is checked once]
//space: O(n) [Recursion is using the call stack; In the worst case, n it will be on the function call stack]


class Solution
{
public:
    bool chk(vector<int> &arr, int i)
    {
        if (i == arr.size())
            return true;
        if (arr[i] < arr[i - 1])
            return false;
        return chk(arr, i + 1);
    }
    bool isSorted(vector<int> &arr)
    {
        return chk(arr, 1);
    }
};