class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++)
        {
            double r = (double)val[i] / wt[i];
            ratio.push_back({r, i});
        }
        sort(ratio.rbegin(), ratio.rend());
        double totalVal = 0.0;
        for (int i = 0; i < n; i++)
        {
            int idx = ratio[i].second;
            if (wt[idx] <= capacity)
            {
                totalVal += val[idx];
                capacity -= wt[idx];
            }
            else
            {
                double fraction = (double)capacity / wt[idx];
                totalVal += val[idx] * fraction;
                break;
            }
        }
        return totalVal;
    }
};