class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>> q;
        for (auto &p : points)
        {
            int x = p[0], y = p[1];
            int dist = x * x + y * y;
            q.push({dist, x, y});
            if (q.size() > k)
                q.pop();
        }
        vector<vector<int>> ans;
        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();
            int x = cur[1], y = cur[2];
            ans.push_back({x, y});
        }
        return ans;
    }
};