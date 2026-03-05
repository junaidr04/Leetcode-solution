// Problem: Count of Smaller Numbers After Self
// Platform: LeetCode
// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// time complexity: O(n log n)
// space complexity: O(n)

class Solution
{
public:
    void merge(vector<pair<int, int>> &a, int l, int mid, int r, vector<int> &ans)
    {
        vector<pair<int, int>> temp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (a[i].first > a[j].first)
            {
                ans[a[i].second] += (r - j + 1);
                temp.push_back(a[i++]);
            }
            else
            {
                temp.push_back(a[j++]);
            }
        }
        while (i <= mid)
        {
            temp.push_back(a[i++]);
        }
        while (j <= r)
        {
            temp.push_back(a[j++]);
        }
        for (int k = 0; k < temp.size(); k++)
        {
            a[l + k] = temp[k];
        }
    }
    void mergeSort(vector<pair<int, int>> &a, int l, int r, vector<int> &ans)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, ans);
        mergeSort(a, mid + 1, r, ans);
        merge(a, l, mid, r, ans);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> a;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            a.push_back({nums[i], i});
        }
        mergeSort(a, 0, n - 1, ans);
        return ans;
    }
};