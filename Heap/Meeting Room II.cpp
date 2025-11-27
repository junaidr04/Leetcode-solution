class Solution
{
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({start[i], end[i]});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        for (auto &p : arr)
        {
            int s = p.first, e = p.second;
            while (!pq.empty() && pq.top() <= s)
                pq.pop();
            pq.push(e);
            count = max(count, (int)pq.size());
        }
        return count;
    }
};
