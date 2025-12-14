class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string prefix = "";
        for (char c : searchWord)
        {
            prefix += c;
            vector<string> temp;
            for (string &p : products)
            {
                if (p.find(prefix) == 0)
                {
                    temp.push_back(p);
                }
                if (temp.size() == 3)
                    break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};