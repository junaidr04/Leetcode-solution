class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> cand(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                cand[i] = cand[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                cand[i] = max(cand[i], cand[i + 1] + 1);
            }
        }
        int ans = 0;
        for (int c : cand)
        {
            ans += c;
        }
        return ans;
    }
};