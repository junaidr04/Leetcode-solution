class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans = "";
        vector<pair<int, char>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true)
        {
            sort(v.rbegin(), v.rend());
            bool add = false;
            for (int i = 0; i < 3; i++)
            {
                int cnt = v[i].first;
                int ch = v[i].second;
                if (cnt == 0)
                    continue;
                int l = ans.size();
                if (l >= 2 && ans[l - 1] == ch && ans[l - 2] == ch)
                    continue;
                ans.push_back(ch);
                v[i].first--;
                add = true;
                break;
            }
            if (!add)
                break;
        }
        return ans;
    }
};