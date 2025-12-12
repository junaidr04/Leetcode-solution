class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        int total = 0;
        for (auto &box : boxTypes)
        {
            int numOfBox = box[0];
            int unitPerBox = box[1];
            int take = min(numOfBox, truckSize);
            total += take * unitPerBox;
            truckSize -= take;
            if (truckSize == 0)
                break;
        }
        return total;
    }
};