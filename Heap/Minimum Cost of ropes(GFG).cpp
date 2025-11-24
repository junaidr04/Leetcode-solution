class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int x : arr)
            q.push(x);
        int total = 0;
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int cost = a + b;
            total += cost;
            q.push(cost);
        }
        return total;
    }
};