class Solution
{
public:
    vector<int> mergeArrays(vector<vector<int>> &mat)
    {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({mat[i][0], i, 0});
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            int val = tmp[0], r = tmp[1], c = tmp[2];
            ans.push_back(val);
            if (c + 1 < mat[r].size())
            {
                pq.push({mat[r][c + 1], r, c + 1});
            }
        }
        return ans;
    }
};