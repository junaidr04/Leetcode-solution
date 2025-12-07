class Solution
{
public:
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        int n = start.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back({finish[i], start[i]});
        }
        sort(a.begin(), a.end());
        int count = 1;
        int lastFinish = a[0].first;
        for (int i = 1; i < n; i++)
        {
            if (a[i].second > lastFinish)
            {
                count++;
                lastFinish = a[i].first;
            }
        }
        return count;
    }
};